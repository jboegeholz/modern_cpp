#include <gtest/gtest.h>
#include <memory>

struct Vec3D
{
    int x{0};
    int y{0};
    int z{0};
};

TEST(MyUniquePointer, OldSchoolPointer)
{
    auto* my_pointer = new Vec3D;
    my_pointer->x = 42;
    EXPECT_EQ(my_pointer->x, 42);
    delete my_pointer;
    my_pointer = nullptr;
    EXPECT_EQ(my_pointer, nullptr);
}

TEST(MyUniquePointer, OldSchoolPointerDoubleDelete)
{
    auto* my_pointer = new Vec3D;
    my_pointer->x = 42;
    EXPECT_EQ(my_pointer->x, 42);
    delete my_pointer;
    delete my_pointer;
    EXPECT_EQ(my_pointer, nullptr);
}

TEST(MyUniquePointer, UniquePointer)
{
    std::unique_ptr<Vec3D> my_pointer(new Vec3D);
    my_pointer->x = 42;
    EXPECT_EQ(my_pointer->x, 42);
}

TEST(MyUniquePointer, MakeUniquePointer)
{
    auto my_pointer = std::make_unique<Vec3D>();
    my_pointer->x = 42;
    EXPECT_EQ(my_pointer->x, 42);
}

void double_unique_ptr()
{
    auto* p = new int(10);
    const std::unique_ptr<int> ptr1{p};
    const std::unique_ptr<int> ptr2{p};
}

TEST(MyUniquePointer, DoubleUniquePointer)
{
    EXPECT_DEATH(double_unique_ptr(), ".*");
}
TEST(MyUniquePointer, Release)
{
    auto p = std::make_unique<int>(10);
    const int* raw = p.release();
    EXPECT_EQ(*raw, 10);
    EXPECT_EQ(p, nullptr);
}