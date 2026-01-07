#include <gtest/gtest.h>
#include <type_traits>

TEST(AutoKeyword, Integer) {

    auto x = 42;
    static_assert(std::is_same_v<decltype(x), int>);
}

TEST(AutoKeyword, Double) {

    auto x = 42.0;
    static_assert(std::is_same_v<decltype(x), double>);
}

TEST(AutoKeyword, String) {

    auto name = "Jörn";
    static_assert(std::is_same_v<decltype(name), const char*>);
}