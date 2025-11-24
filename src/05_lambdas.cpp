#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

bool sort_descending(const float a, const float b){
    return a > b;
}

void print_vector(const std::vector<float>& numbers) {
    for (const float x : numbers) {
        std::cout << std::fixed << std::setprecision(1) << x << " | ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<float> numbers = { -3.5, 1.0, -2.0, -11.0};
    std::cout << "Unsorted Vector:" << std::endl;
    print_vector(numbers);

    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted ascending:" << std::endl;
    print_vector(numbers);

    // sort descending
    std::sort(numbers.begin(), numbers.end(), sort_descending);
    std::cout << "Sorted descending:" << std::endl;
    print_vector(numbers);

    // sort descending with lambda
    std::sort(numbers.begin(), numbers.end());

    std::sort(numbers.begin(), numbers.end(), [] (const float a, const float b) -> bool {return a > b;});
    std::cout << "Sorted descending with lambdas:" << std::endl;
    print_vector(numbers);

    return 0;
}

