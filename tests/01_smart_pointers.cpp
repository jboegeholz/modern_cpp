#include <gtest/gtest.h>
#include <cstddef>
namespace  JB
{
    template <typename T>
    class unique_ptr
    {
    public:
        explicit unique_ptr(T * ptr) : underlying_ptr(ptr) {}
        unique_ptr() : underlying_ptr(nullptr) {}
        bool operator==(std::nullptr_t) const noexcept {
            return underlying_ptr == nullptr;
        }

        bool operator!=(std::nullptr_t) const noexcept {
            return underlying_ptr != nullptr;
        }
    private:
        T * underlying_ptr;
    };
}
TEST(UniquePointer, UniquePointerInstantiate) {
    const JB::unique_ptr<int> p {new int(10)};
    EXPECT_NE(p, nullptr);
}

TEST(UniquePointer, UniquePointerInstantiateNull) {
    const JB::unique_ptr<int> p;
    EXPECT_EQ(p, nullptr);
}