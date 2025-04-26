#include <iostream>
#include <array>

int main() {
    std::cout << "C-Style array" << std::endl;
    int my_values[] = {1, 2 ,3, 4};

    for (const int i : my_values)
    {
        std::cout << i << std::endl;
    }
    std::array<std::int32_t, 4> my_std_array = {8, 7, 6, 5};
    try
    {
        std::cout << "Element at postion 4: " << my_std_array.at(4) << std::endl;
    }
    catch (const std::out_of_range& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}