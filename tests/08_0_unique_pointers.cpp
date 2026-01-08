#include <gtest/gtest.h>
#include <cstddef>
#include <memory>


void double_unique_ptr() {
    auto * p = new int(10);
    const std::unique_ptr<int> ptr1 {p};
    const std::unique_ptr<int> ptr2 {p};
}
TEST(MyUniquePointer, DoubleUniquePointer) {
    EXPECT_DEATH(double_unique_ptr(), ".*");
}

