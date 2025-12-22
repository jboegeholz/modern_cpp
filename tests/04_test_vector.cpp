#include <gtest/gtest.h>
#include <vector>

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