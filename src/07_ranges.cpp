#include <ranges>
#include <cassert>

int main() {
    std::vector<float> numbers = { -3.5, 1.0, -2.0, -11.0};
    const std::vector<float> sorted = {-11.0, -3.5, -2.0, 1.0};
    const std::vector<float> sorted_desc = { 1.0, -2.0, -3.5, -11.0};

    std::ranges::sort(numbers.begin(), numbers.end());
    assert (numbers == sorted);

    std::ranges::sort(numbers, {}, [](const float x) { return std::abs(x); });

    assert (numbers == sorted_desc);
}
