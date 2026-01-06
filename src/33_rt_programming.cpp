#include <pthread.h>
#include <sched.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
#include <atomic>
#include <cerrno>
#include <cstring>
#include <iostream>

static inline timespec add_ns(timespec t, long ns) {
  t.tv_nsec += ns;
  while (t.tv_nsec >= 1000000000L) { t.tv_nsec -= 1000000000L; t.tv_sec += 1; }
  return t;
}

std::atomic<bool> run{true};

void* rt_loop(void*) {
  // Optional: Name (hilft beim Debugging mit top/htop)
  pthread_setname_np(pthread_self(), "rt_control");

  // 1 kHz = 1'000'000 ns
  const long period_ns = 1'000'000L;

  // Absolute Zeitbasis (vermeidet Drift)
  timespec next{};
  clock_gettime(CLOCK_MONOTONIC, &next);

  while (run.load(std::memory_order_relaxed)) {
    next = add_ns(next, period_ns);

    // ---- RT-Work hier: read -> control -> write ----
    // Keine Allokation, kein Logging, keine blockierenden Calls.
    // -----------------------------------------------

    // Schlaf bis zur absoluten Deadline
    int rc = clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, nullptr);
    if (rc != 0 && rc != EINTR) {
      // In echter RT-Software würde man hier nicht std::cerr benutzen,
      // sondern einen non-RT Fehlerpfad / Flag setzen.
      std::cerr << "clock_nanosleep error: " << std::strerror(rc) << "\n";
    }
  }
  return nullptr;
}

int main() {
  // 1) Speicher sperren (keine Page Faults während Laufzeit)
  if (mlockall(MCL_CURRENT | MCL_FUTURE) != 0) {
    std::cerr << "mlockall failed: " << std::strerror(errno) << "\n";
    // Für echtes RT oft: abort, oder mit degraded mode weiter.
  }

  // Optional: Stack pre-fault (Stack "anfassen", um Pages zu mappen)
  volatile char stack_touch[64 * 1024];
  for (size_t i = 0; i < sizeof(stack_touch); i += 4096) stack_touch[i] = 0;

  pthread_t thread{};
  pthread_attr_t attr{};
  pthread_attr_init(&attr);

  // 2) Scheduling explizit setzen
  pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setschedpolicy(&attr, SCHED_FIFO);

  sched_param sp{};
  sp.sched_priority = 80; // 1..99 (typisch: control hoch, aber unter IRQ/critical)
  pthread_attr_setschedparam(&attr, &sp);

  // 3) CPU Affinity pinnen (z.B. CPU 2)
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(2, &cpuset);
  pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpuset);

  int rc = pthread_create(&thread, &attr, &rt_loop, nullptr);
  pthread_attr_destroy(&attr);

  if (rc != 0) {
    std::cerr << "pthread_create failed: " << std::strerror(rc) << "\n";
    std::cerr << "Hinweis: SCHED_FIFO braucht oft CAP_SYS_NICE oder root.\n";
    return 1;
  }

  sleep(2);
  run.store(false);
  pthread_join(thread, nullptr);
  return 0;
}
