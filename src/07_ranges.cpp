#include <algorithm>
#include <ranges>
#include <cassert>
#include <vector>

using std::ranges::sort;
int main() {
    std::vector<float> numbers = { -3.5, 1.0, -2.0, -11.0};
    const std::vector<float> sorted = {-11.0, -3.5, -2.0, 1.0};
    const std::vector<float> sorted_desc = { 1.0, -2.0, -3.5, -11.0};

    sort(numbers);
    assert (numbers == sorted);

    sort(numbers, {}, [](const float x) { return std::abs(x); });

    assert (numbers == sorted_desc);
}
