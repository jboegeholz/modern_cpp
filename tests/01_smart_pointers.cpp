#include <gtest/gtest.h>
#include <cstddef>
#include <memory>
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


TEST(UniquePointer, UniquePointerInstantiateNull) {
    {
        auto entity = std::make_unique<Entity>();
        EXPECT_NE(entity, nullptr);
    }
}