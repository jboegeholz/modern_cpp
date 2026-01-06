#include <gtest/gtest.h>

class MyBuffer {
public:
    explicit MyBuffer(const size_t size)
           : size_(size), data_(new int[size]){};
    ~MyBuffer() {
        delete[] data_;
    }
    MyBuffer(const MyBuffer & other)
    :size_(other.size_), data_(new int[other.size_]) {
        std::copy(other.data_, other.data_ + other.size_, data_);

    }
private:
    size_t size_;
    int* data_;
};


TEST(ConstructorTest, DefaultCTor) {
    const MyBuffer myclass(5);
    SUCCEED();
}

TEST(ConstructorTest, CopyCTor) {
    const MyBuffer myclass(5);
    const MyBuffer mycopy = myclass;
    SUCCEED();
}