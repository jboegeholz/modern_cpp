#include <gtest/gtest.h>
#include <vector>

struct Vec3D
{
    int x, y, z;
    Vec3D(const int x, const int y, const int z) : x(x), y(y), z(z) {}
    bool operator==(const Vec3D & rhs) const
    {
        if (x == rhs.x && y == rhs.y && z == rhs.z)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

TEST(VectorTest, VectorInitialSize) {
    const std::vector<int> int_vector;
    EXPECT_EQ(int_vector.capacity(), 0);
    EXPECT_EQ(int_vector.size(), 0);
    EXPECT_EQ(int_vector.empty(), true);
}

TEST(VectorTest, VectorPushBack) {
    std::vector<int> int_vector;
    int_vector.push_back(1);
    int_vector.push_back(2);
    int_vector.push_back(3);
    EXPECT_EQ(int_vector.size(), 3);

#if defined(_MSC_VER)
    EXPECT_EQ(int_vector.capacity(), 3);
#elif defined(__clang__) || defined(__GNUC__)
    EXPECT_EQ(int_vector.capacity(), 4);
#endif

    int_vector.push_back(4);
    EXPECT_EQ(int_vector.size(), 4);
    EXPECT_EQ(int_vector.capacity(), 4);

    int_vector.push_back(5);
    EXPECT_EQ(int_vector.size(), 5);

#if defined(_MSC_VER)
    EXPECT_EQ(int_vector.capacity(), 6);
#elif defined(__clang__) || defined(__GNUC__)
    EXPECT_EQ(int_vector.capacity(), 8);
#endif

}

TEST(VectorTest, VectorGetElement) {
    const std::vector<int> int_vector = {1,2,3,4,5};

    EXPECT_EQ(int_vector[2], 3);
    EXPECT_EQ(int_vector.at(2), 3);
}

TEST(VectorTest, VectorGetElementException) {
    const std::vector<int> int_vector = {1,2,3,4,5};
    EXPECT_THROW((void)int_vector.at(10), std::out_of_range);
}

TEST(VectorTest, VectorElementBackFront) {
    const std::vector<int> int_vector = {1,2,3};
    EXPECT_EQ(int_vector.front(), 1);
    EXPECT_EQ(int_vector.back(), 3);
}

TEST(VectorTest, VectorElementPopBack) {
    std::vector<int> int_vector = {1,2,3};
    int_vector.pop_back();
    EXPECT_EQ(int_vector.size(), 2);
}
TEST(VectorTest, VectorElementInsert) {
    std::vector<int> int_vector = {1,2,3};
    int_vector.insert(int_vector.begin(), 0);
    EXPECT_EQ(int_vector.at(0), 0);
}

TEST(VectorTest, VectorReserve) {
    std::vector<int> int_vector;
    int_vector.reserve(100);
    EXPECT_EQ(int_vector.capacity(), 100);
}

TEST(VectorTest, VectorEmplaceBack) {
    std::vector<Vec3D> my_vector;
    my_vector.emplace_back(1, 2, 3 );
    EXPECT_EQ(my_vector.at(0), Vec3D(1, 2, 3));
}