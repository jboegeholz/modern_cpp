#include <gtest/gtest.h>
#include <chrono>
TEST(ChronotTest, Integer) {
    using namespace std::chrono_literals;
    const auto start = std::chrono::high_resolution_clock::now();

    std::this_thread::sleep_for(2s);

    const auto stop = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli>diff = stop - start;
    EXPECT_GE(diff, 2000ms);

}

