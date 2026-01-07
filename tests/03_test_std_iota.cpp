#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <numeric>


TEST(IOTA, Integer) {

    std::vector<int> numbers(5);
    constexpr int startValue = 10;
    std::iota(numbers.begin(), numbers.end(), startValue);

    EXPECT_EQ(numbers[0], 10);
}
