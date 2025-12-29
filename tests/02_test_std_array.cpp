#include <gtest/gtest.h>
#include <array>

TEST(ArrayTest, CStyleArray) {
    int my_int_array[3] = {1, 2, 3};
    EXPECT_EQ(my_int_array[0], 1);
    EXPECT_EQ(my_int_array[1], 2);
    EXPECT_EQ(my_int_array[2], 3);
}

TEST(ArrayTest, CStyleArraySize) {
    int my_int_array[3];
    double my_double_array[3];
    EXPECT_EQ(sizeof(my_int_array), 12);
    EXPECT_EQ(sizeof(my_double_array), 24);
}

int get_size(const int *arr)
{
    return sizeof(arr);
}
TEST(ArrayTest, CStyleArrayPointerDecay) {
    int my_int_array[3];
    EXPECT_EQ(sizeof(my_int_array), 12);
    EXPECT_EQ(get_size(my_int_array), 8); // decays to 64bit pointer
}
TEST(ArrayTest, CStyleArrayIndex) {
    int my_int_array[3] = {1, 2, 3};
    my_int_array[4] = 1;
    EXPECT_EQ(my_int_array[4], 1);

}

TEST(ArrayTest, StdArray) {
    std::array<int, 3> my_std_array = {1, 2, 3};

    EXPECT_EQ(my_std_array[0], 1);
    EXPECT_EQ(my_std_array[1], 2);
    EXPECT_EQ(my_std_array[2], 3);

}
TEST(ArrayTest, StdArraySize) {
    std::array<int, 3> my_int_array{};
    std::array<int64_t, 3> my_int_64_array{};
    EXPECT_EQ(my_int_array.size(), 3);
    EXPECT_EQ(my_int_64_array.size(), 3);
}

TEST(ArrayTest, AddElementsToArray) {
    std::array<int, 3> my_array{};
    my_array[0] = 1;
    my_array[1] = 2;
    my_array[2] = 3;
    EXPECT_EQ(my_array[0], 1);
    EXPECT_EQ(my_array[1], 2);
    EXPECT_EQ(my_array[2], 3);
}
TEST(ArrayTest, AddElementsToArrayWithAt) {
    std::array<int, 3> my_array{};
    my_array.at(0) = 1;
    my_array.at(1) = 2;
    my_array.at(2) = 3;
    EXPECT_EQ(my_array[0], 1);
    EXPECT_EQ(my_array[1], 2);
    EXPECT_EQ(my_array[2], 3);
}

TEST(ArrayTest, ArrayGetElementException) {
    const std::array<int, 3> my_array = {1,2,3};
    EXPECT_THROW((void)my_array.at(10), std::out_of_range);
}

TEST(ArrayTest, ArrayTestCatchException) {
    std::array<int, 4> my_std_array = {8, 7, 6, 5};

    try
    {
        std::cout << "Element at postion 4: " << my_std_array.at(4) << std::endl;
    }
    catch (const std::out_of_range& ex)
    {
        std::cerr << ex.what() << '\n';
        EXPECT_NE(ex.what(), nullptr);
    }
}

