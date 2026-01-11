#include <gtest/gtest.h>
#include <memory>

struct Vec3D
{
    int x{0};
    int y{0};
    int z{0};
};

TEST(MyUniquePointer, UniquePointer)
{
    const auto my_pointer = std::make_shared<Vec3D>();
    my_pointer->x = 42;
    EXPECT_EQ(my_pointer->x, 42);
}