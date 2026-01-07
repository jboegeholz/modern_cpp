#include <gtest/gtest.h>
#include <iomanip>
#include <algorithm>
#include <vector>

bool sort_descending(const float a, const float b)
{
    return a > b;
}


TEST(LambdasTest, StdSort)
{
    std::vector<float> numbers = {-3.5, 1.0, -2.0, -11.0};
    std::sort(numbers.begin(), numbers.end());
    EXPECT_FLOAT_EQ(numbers[0], -11.0);
}

TEST(LambdasTest, StdSortDesc)
{
    std::vector<float> numbers = {-3.5, 1.0, -2.0, -11.0};
    std::sort(numbers.begin(), numbers.end(), sort_descending);
    EXPECT_FLOAT_EQ(numbers[0], 1.0);
}

TEST(LambdasTest, StdSortDescLambda)
{
    std::vector<float> numbers = {-3.5, 1.0, -2.0, -11.0};
    std::sort(numbers.begin(), numbers.end(), [](const float a, const float b) -> bool { return a > b; });
    EXPECT_FLOAT_EQ(numbers[0], 1.0);
}

TEST(LambdasTest, InnerFunction)
{
    auto twice = [](const auto& x)
    {
        return 2 * x;
    };
    EXPECT_EQ(twice(4), 8);
}
