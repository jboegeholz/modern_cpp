#include <gtest/gtest.h>
#include <print>   // C++23

TEST(PrintTest, StdPrint) {
    testing::internal::CaptureStdout();

    std::print("Hello World");

    const std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello World");
}

TEST(PrintTest, StdPrintLn) {
    testing::internal::CaptureStdout();

    std::println("Hello World");

    const std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello World\n");
}

TEST(PrintTest, StdPrintExtrapolation) {
    testing::internal::CaptureStdout();

    std::print("Hello {}", "World");

    const std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello World");
}