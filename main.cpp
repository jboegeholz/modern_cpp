#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

template<typename T>
void output_type(const T& var) {
    const char* mangled = typeid(var).name();

    int status;
    const std::unique_ptr<char, void(*)(void*)> demangled{
        abi::__cxa_demangle(mangled, nullptr, nullptr, &status),
        std::free
    };
    if (status == 0 && demangled)
        std::cout << "Typ: " << demangled.get() << '\n';
    std::cout << "Typ (mangled): " << mangled << '\n';

}

int main() {

    auto age = 42;
    output_type(age);
    auto weight = 86.6;
    output_type(weight);
    auto name = "Jörn";
    output_type(name);

    return 0;
}
