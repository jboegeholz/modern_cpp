#include <span>
#include <iostream>

void print(const std::span<const int> values) {
    for (const int v : values) {
        std::cout << v << " ";
    }
    std::cout << '\n';
}

int main() {
    const int arr[] = {1, 2, 3, 4, 5};
    print(arr);
}