#include <gtest/gtest.h>
#include <vector>

TEST(VectorTest, IntVectorInitialSize) {
    std::vector<int> int_vector;
    EXPECT_EQ(int_vector.capacity(), 0);
    EXPECT_EQ(int_vector.size(), 0);
    EXPECT_EQ(int_vector.empty(), true);
}

TEST(VectorTest, IntVectorPushBack) {
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

}