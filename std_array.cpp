#include <iostream>

int main() {
    std::cout << "C-Style array" << std::endl;
    int my_values[] = {1, 2 ,3, 4};

    for (const int i : my_values)
    {
        std::cout << i << std::endl;
    }
}