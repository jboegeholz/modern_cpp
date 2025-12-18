#include <iostream>
#include <cassert>
#include <vector>
#include <initializer_list>
struct Vec3D
{
    int x{}, y{}, z{};
    Vec3D()
    {
        std::cout << "default c'tor\n";
    };
    Vec3D(const std::initializer_list<int> list)
    {
        std::cout << "initializer_list ctor" << std::endl;
        if (!std::empty(list)) {
            for (const auto& i : list)
                std::cout << i << ", ";

            std::cout << "(" << list.size() << " elements)\n";
        }
        else
            std::cout << "empty list\n";

    }
    Vec3D(const int x, const int y, const int z) : x(x), y(y), z(z)
    {
        std::cout << "c'tor\n";
    }
    ~Vec3D()
    {
        std::cout << "d'tor\n";
    };
    Vec3D(const Vec3D& other)
    {
        std::cout << "copy c'tor\n";
        x = other.x;
        y = other.y;
        z = other.z;
    }
    Vec3D& operator=(const Vec3D& other) {
        if (this != &other) {
            std::cout << "copy assignment c'tor\n";
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
    // Move Assignment Operator
    Vec3D& operator=(Vec3D&& other) noexcept {
        if (this != &other) {
            std::cout << "move assignment c'tor\n";
        }
        return *this;
    }

};
int main()
{
    const Vec3D v1;
    assert(v1.x == 0);
    assert(v1.y == 0);
    assert(v1.z == 0);

    const Vec3D v3(1,2,3);
    assert(v3.x == 1);
    assert(v3.y == 2);
    assert(v3.z == 3);

    const Vec3D v2 = {1,2,3};
    /*assert(v2.x == 1);
    assert(v2.y == 2);
    assert(v2.z == 3);*/


    Vec3D v4;
    v4 = v3;
    Vec3D v5 = std::move(v3);

    std::cout << "vector with c'tor" << std::endl;
    std::vector<Vec3D> vec_vec;
    vec_vec.reserve(2);
    vec_vec.push_back({4,5,6});
    vec_vec.emplace_back(7,8,9);

}