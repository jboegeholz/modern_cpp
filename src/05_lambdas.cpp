#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <ranges>

int main() {
    std::vector<float> numbers = { -3.5f, 1.0f, -2.0f };

    for (float x : numbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::ranges::sort(numbers);
    for (const float x : numbers) {
        std::cout << x << " < ";
    }
    std::cout << std::endl;

    std::ranges::sort(numbers,
                      [](float a, float b) {
                          return std::abs(a) < std::abs(b);
                      }
    );
    for (const float x : numbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::ranges::sort(numbers, {}, [](float x) { return std::abs(x); });

    for (const float x : numbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}

void abssort(float* x, unsigned n) {

}