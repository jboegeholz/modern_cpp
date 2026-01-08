#include <span>
#include <iostream>
#include <gtest/gtest.h>

void print(const std::span<const int> values) {
    for (const int v : values) {
        std::cout << v << " ";
    }
}
TEST(SpanTest, StdPrintExtrapolation) {
    testing::internal::CaptureStdout();

    const int arr[] = {1, 2, 3, 4, 5};
    print(arr);

    const std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 4 5 ");
}