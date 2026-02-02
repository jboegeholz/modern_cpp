#include <expected>
#include <iostream>
#include <string>
#include <optional>
#include <gtest/gtest.h>
std::optional<int> asInt(const std::string& s) // returns int or "no int"
{
    try {
        return std::stoi(s);
    }
    catch (...) {
        return {};  // return std::nullopt;
    }
}

TEST(OptionalTest, StdPrintExtrapolation) {
    testing::internal::CaptureStdout();

    for (const auto s : {"42", " 077", "hello", "0x33"} ) {
        if (std::optional<int> oi = asInt(s)) {
            std::cout << "convert '" << s << "' to int: " << *oi << "\n"; // int
        }
        else {
            std::cout << "can't convert '" << s << "' to int\n"; // "no int"
        }
    }

    const std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "convert '42' to int: 42\nconvert ' 077' to int: 77\ncan't convert 'hello' to int\nconvert '0x33' to int: 0\n");
}

std::expected<int, std::string> divide(const int dividend, const int divisor)
{
    if (divisor == 0) {
        return std::unexpected("Division by zero is not allowed.");
    }
    return dividend / divisor;
}
TEST(OptionalTest, ExpectedTest)
{
    const auto result = divide(10, 2);
    EXPECT_EQ(5, result.value());
    const auto result2 = divide(10, 0);
    EXPECT_EQ(result2, std::unexpected("Division by zero is not allowed."));
}