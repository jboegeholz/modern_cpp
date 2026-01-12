#include <gtest/gtest.h>
#include <vector>
#include <ranges>
#include <algorithm>

TEST(RangesTest, Ascending)
{
    using std::ranges::sort;
    std::vector<float> numbers = {-3.5, 1.0, -2.0, -11.0};
    const std::vector<float> sorted = {-11.0, -3.5, -2.0, 1.0};

    sort(numbers);

    EXPECT_EQ(numbers, sorted);
}

TEST(RangesTest, Descending)
{
    using std::ranges::sort;
    std::vector<float> numbers = {-3.5, 1.0, -2.0, -11.0};
    const std::vector<float> sorted_desc = {1.0, -2.0, -3.5, -11.0};

    sort(numbers, {}, [](const float x) { return std::abs(x); });

    EXPECT_EQ(numbers, sorted_desc);
}

TEST(RangesTest, TestViews)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    std::vector<int> expected_result = {36, 16, 4};
    auto results = numbers | std::views::filter([] (const int n) {return n % 2 == 0;})
                                     | std::views::transform([] (const int n){return n*n;})
                                     | std::views::reverse
                                     | std::ranges::to<std::vector>();
    EXPECT_EQ(results, expected_result);
}
