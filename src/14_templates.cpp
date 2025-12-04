#include <iostream>
#include <set>
#include <vector>
#include "stack.hpp"
template<typename T>
T mymax(T a, T b)
{
    return b < a ? a : b;
}
template<typename T>
void print(const T& coll)
{
    for (const auto& elem : coll) {
        std::cout << elem << '\n';
    }
}
int main()
{
    constexpr int i1=42;
    constexpr int i2=77;
    std::cout << mymax(i1, i2) << std::endl;
    std::cout << mymax(0.7, 33.4) << std::endl;
    std::string s{"hi"}, t{"world"};
    std::cout << mymax(s, t) << std::endl;

    const std::vector<int> numbers = {1,2,3,4,5,6,7,8,9};
    print(numbers);
    const std::set<std::string> words = {"one", "two", "three"};
    print(words);
    //
    Stack<int> intStack;
    intStack.push(7);
    std::cout << intStack.top() << '\n';

    Stack<std::string> strStack;
    strStack.push("Hello");
    std::cout << strStack.top() << '\n';
    Stack<double> doubleStack;
    doubleStack.push(3.0);
    std::cout << doubleStack.top() << '\n';

}