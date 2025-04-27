
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> coll{ 1, 2, 3, 5, 8, 9, 11, 13, 17 };  // initialize vector with values

    for (unsigned i = 0; i < coll.size(); ++i) {   // print elements with index operator
        std::cout << coll[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "capacity(): " << coll.capacity() << '\n';

    coll.push_back(15);                            // append one element
    std::cout << "capacity(): " << coll.capacity() << '\n';

    for (int elem : coll) {                        // print elements with range-based for loop
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    coll.insert(coll.begin(), { 0, 8, 23 });         // insert multiple elements

    std::sort(coll.begin(), coll.end());           // sort all elements
    for (auto pos = coll.begin(); pos != coll.end(); ++pos) {  // low-level loop with iterator
        std::cout << *pos << ' ';                                // printing each element
    }
    std::cout << '\n';

    std::sort(coll.begin(), coll.end(),            // sort all elements descending
        [](auto x, auto y) { return x > y; });
    for (auto pos = coll.begin(); pos != coll.end(); ++pos) {  // low-level loop with iterator
        std::cout << *pos << ' ';                                // printing each element
    }
    std::cout << '\n';
}