#include <chrono>
#include <iostream>

int main()
{
    auto start_1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1'000'000; ++i) {
        std::cout << i << '\n';
        //std::cout << i << std::endl;
    }
    auto end_1 = std::chrono::high_resolution_clock::now();


    auto start_2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1'000'000; ++i) {
        //std::cout << i << '\n';
        std::cout << i << std::endl;
    }
    auto end_2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_1 - start_1);
    std::cout << "time for CR " << duration.count() << " microseconds\n";
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end_2 - start_2);
    std::cout << "time for std::endl " << duration.count() << " microseconds\n";
}

