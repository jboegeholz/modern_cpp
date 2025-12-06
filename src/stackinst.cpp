#include "stackdef.hpp"
#include <string>
// instantiate class Stack<> for int:
template class Stack<int>;
template class Stack<double>;
// instantiate some member functions of Stack<> for strings:
template void Stack<std::string>::push(const std::string&);
template const std::string& Stack<std::string>::top() const;

