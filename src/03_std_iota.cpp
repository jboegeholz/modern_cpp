#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers(5);
    constexpr std::int32_t startValue = 10;

    std::iota(numbers.begin(), numbers.end(), startValue);

    for (const int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}