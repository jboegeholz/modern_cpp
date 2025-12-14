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
    int x, y, z;
    Vec3D(const int x, const int y, const int z) : x(x), y(y), z(z) {}
};
int main()
{
    std::cout << s_allocations.current_usage() << std::endl;
    std::vector<Vec3D> my_vector;
    my_vector.reserve(20);
    std::cout << s_allocations.current_usage() << std::endl;
    for (int i=0; i < 20; ++i)
    {
        my_vector.emplace_back(1, 2, 3 );
    }
    std::cout << s_allocations.current_usage() << std::endl;

}
