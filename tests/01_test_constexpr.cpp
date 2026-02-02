
#include <gtest/gtest.h>
#include <numbers>

constexpr double PI = std::numbers::pi;
constexpr double E = std::numbers::e;


constexpr int square(int x) {
    return x * x;
}
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

static_assert(square(4) == 16);
static_assert(factorial(5) == 120);
constexpr int sum(int n) {
    int result = 0;
    for (int i = 1; i <= n; ++i)
        result += i;
    return result;
}


static_assert(sum(10) == 55);
static_assert(sum(11) == 66);
TEST(ConstexprTest, LoopRuntime) {
    EXPECT_EQ(sum(10), 55);
}

struct Point {
    int x;
    int y;

    constexpr Point(int x_, int y_) : x(x_), y(y_) {}
};
static_assert(Point{1, 2}.x == 1);