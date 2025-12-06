#ifndef STACKDEF_HPP
#define STACKDEF_HPP
#include "stack.hpp"

template<typename T>
void Stack<T>::push(const T& val)
{
    elems.push_back(val);
}

template<typename T>
const T& Stack<T>::top() const
{
    return elems.back();
}
#endif // STACKDEF_HPP