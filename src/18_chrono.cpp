#include <iostream>
#include <chrono>
#include <thread>
int main() {
    using namespace std::chrono_literals;
    std::cout << "Hello Chrono Package" << std::endl;
    const auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2000ms);
    const auto stop = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli>diff = stop - start;
    std::cout << "diff: " << diff;

}