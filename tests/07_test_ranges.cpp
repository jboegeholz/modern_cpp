#include <gtest/gtest.h>
#include <algorithm>

TEST(RangesTest, Ascending)
{
    using std::ranges::sort;
    std::vector<float> numbers = { -3.5, 1.0, -2.0, -11.0};
    const std::vector<float> sorted = {-11.0, -3.5, -2.0, 1.0};

    sort(numbers);

    EXPECT_EQ(numbers, sorted);
}

TEST(RangesTest, Descending)
{
    using std::ranges::sort;
    std::vector<float> numbers = { -3.5, 1.0, -2.0, -11.0};
    const std::vector<float> sorted_desc = { 1.0, -2.0, -3.5, -11.0};

    sort(numbers, {}, [](const float x) { return std::abs(x); });

    EXPECT_EQ(numbers, sorted_desc);
}