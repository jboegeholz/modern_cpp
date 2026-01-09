#include <gtest/gtest.h>

class MyBuffer3
{
public:
    explicit MyBuffer3(const size_t size)
        : size_(size), data_(new int[size])
    {
    };

    void set_buffer(const int index, const int value) const
    {
        data_[index] = value;
    }

    [[nodiscard]] int get_buffer(const int index) const
    {
        return data_[index];
    }

    ~MyBuffer3()
    {
        delete[] data_;
    }


    // copy c'tor
    MyBuffer3(const MyBuffer3& other)
        : size_(other.size_), data_(new int[other.size_])
    {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    MyBuffer3& operator=(const MyBuffer3& other)
    {
        if (this == &other) {
            return *this;
        }
        size_ = other.size_;
        delete[] data_;
        data_ = new int[size_];
        std::copy(other.data_, other.data_ + other.size_, data_);
        return *this;
    }

private:
    size_t size_;
    int* data_;
};


TEST(ConstructorTest, DefaultCTor)
{
    MyBuffer3 my_buffer(3);
    my_buffer.set_buffer(0, 123);
    my_buffer.set_buffer(1, 234);
    my_buffer.set_buffer(2, 456);
    EXPECT_EQ(my_buffer.get_buffer(0), 123);
}

TEST(ConstructorTest, CopyCTor)
{
    MyBuffer3 my_buffer(5);
    my_buffer.set_buffer(0, 123);
    const MyBuffer3 my_buffer_copy(my_buffer);
    EXPECT_EQ(my_buffer_copy.get_buffer(0), 123);
}

TEST(ConstructorTest, AssignementCopyCTor)
{
    MyBuffer3 my_buffer(3);
    my_buffer.set_buffer(0, 123);
    my_buffer.set_buffer(1, 234);
    my_buffer.set_buffer(2, 456);
    MyBuffer3 my_buffer_copy(3);
    my_buffer_copy = my_buffer;
    EXPECT_EQ(my_buffer_copy.get_buffer(0), 123);
}
