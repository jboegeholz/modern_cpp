#ifndef STACK_HPP
#define STACK_HPP
#include <vector>
template<typename T>
class Stack {

public:
    Stack() = default; // constructor
    void push(const T&); // push element
    const T& top() const; // yield top element
private:
    std::vector<T> elems; // elements

};
#endif // STACK_HPP