
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main()
{
    std::vector<int> int_vector;
    std::vector<double> double_vector;
    assert( int_vector.capacity() == 0);
    assert( int_vector.empty());

    // add values at back
    int_vector.push_back(1);
    int_vector.push_back(2);
    int_vector.push_back(3);
    assert( int_vector.size() == 3);
#if defined(__clang__)
    assert(int_vector.capacity() == 4);
#else
    assert(int_vector.capacity() == 3);
#endif

    int_vector.push_back(4);
    assert( int_vector.size() == 4);
    assert( int_vector.capacity() == 4);
    int_vector.push_back(5);
    assert( int_vector.size() == 5 );
#if defined(__clang__)
    assert(int_vector.capacity() == 8);
#else
    assert(int_vector.capacity() == 6);
#endif

    // get element via index
    assert(int_vector.at(1) == 2);
    assert(int_vector[2] == 3);

    // out of range
    try {
        int_vector.at(10) = 4;      // vector::at throws an out-of-range
    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Out of Range error: " << ex.what() << '\n';
    }

    // get last element
    assert(int_vector.back() == 5);

    // get first element
    assert(int_vector.front() == 1);

    // remove last element
    int_vector.pop_back();
    assert(int_vector.size() == 4);

    int_vector.insert(int_vector.begin(), 0);
    assert(int_vector.at(0) == 0);

    std::vector<int> v;
    for (int i = 0; i < 20; ++i) {
        v.push_back(i);
        std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << '\n';
    }


    std::vector<std::string> str_vector;
    str_vector.reserve(6);
    str_vector.emplace_back("Hello");
    str_vector.emplace_back("World");

}
