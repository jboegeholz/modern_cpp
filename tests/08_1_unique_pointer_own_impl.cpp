#include <gtest/gtest.h>

#include <memory>
#include <type_traits>
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
        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete;
    private:
        T * underlying_ptr;
    };
}
class Entity
{
public:
    Entity()
    {
        std::cout << "Created" << std::endl;
    };
    ~Entity()
    {
        std::cout << "Destroyed" << std::endl;
    };
};

TEST(MyUniquePointer, UniquePointerInstantiate) {
    const JB::unique_ptr<int> p {new int(10)};
    EXPECT_NE(p, nullptr);
}

TEST(MyUniquePointer, UniquePointerInstantiateNull) {
    const JB::unique_ptr<int> p;
    EXPECT_EQ(p, nullptr);
}


TEST(UniquePointer, NoCopyCtor) {
    static_assert(!std::is_copy_constructible_v<JB::unique_ptr<Entity>>,
                  "MyType must not be copy constructible");
}
TEST(UniquePointer, NoAssignmentOperator) {
    static_assert(!std::is_copy_assignable_v<JB::unique_ptr<Entity>>,
                  "MyType must not be copy constructible");
}