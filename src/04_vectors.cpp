
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main()
{
    std::vector<int> coll;
    assert( coll.capacity() == 0);
    assert( coll.empty());

    // add values at back
    coll.push_back(1);
    coll.push_back(2);
    coll.push_back(3);
    assert( coll.size() == 3);

    // get element via index
    assert(coll.at(1) == 2);

    // out of range
    try {
        coll.at(3) = 4;      // vector::at throws an out-of-range
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

    // get last element
    assert(coll.back() == 3);

    // get first element
    assert(coll.front() == 1);

    // remove last element
    coll.pop_back();
    assert(coll.size() == 2);


}
