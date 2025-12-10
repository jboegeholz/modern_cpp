#include <iostream>
#include <memory>
#include <vector>

struct AllocationMetrics
{
    uint32_t total_allocated = 0;
    uint32_t total_freed = 0;
    [[nodiscard]] uint32_t current_usage() const{return total_allocated - total_freed; }
};
static AllocationMetrics s_allocations;

void* operator new(size_t size)
{
    std::cout << "allocated " << size << " bytes" << std::endl;
    s_allocations.total_allocated += static_cast<uint32_t>(size);
    return malloc(size);
}
void operator delete(void* memory, size_t size)
{
    std::cout << "deallocated " << size << " bytes" << std::endl;
    s_allocations.total_freed += static_cast<uint32_t>(size);
    free(memory);
}
struct Vec3D
{
    std::byte x, y, z;
    Vec3D(const std::byte x_, const std::byte y_, const std::byte z_) : x(x_), y(y_), z(z_) {}
};
int main()
{
    std::cout << s_allocations.current_usage() << std::endl;
    std::vector<Vec3D> my_vector;
    std::cout << s_allocations.current_usage() << std::endl;
    for (int i=0; i < 20; ++i)
    {
        my_vector.emplace_back(static_cast<std::byte>(1),static_cast<std::byte>(2),static_cast<std::byte>(3));
    }
    std::cout << s_allocations.current_usage() << std::endl;

}
