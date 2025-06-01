#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cxxabi.h>
#include <string_view>
#include <mutex>

void test_variables() {
    int age = 42;
    double height = 1.81;
    const char* name = "Joern";
    std::cout << age << std::endl;
    std::cout << height << std::endl;
    std::cout << name << std::endl;

    auto new_age = 42;
    auto new_height = 1.81;
    auto new_name = "Joern";

    std::cout << new_age << std::endl;
    std::cout << new_height << std::endl;
    std::cout << new_name << std::endl;
    std::cout << typeid(new_age).name() << std::endl;
    std::cout << typeid(new_height).name() << std::endl;
    std::cout << typeid(new_name).name() << std::endl;
}

void test_for_loops() {
    std::vector<int> v = {1, 2, 3};

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << '\n';

    for (const auto& value : v)
        std::cout << value << '\n';
}

void unsused_param(std::string name)
{
    std::cout << "unsused_param" << '\n';
}

void test_compiler_options() {
    int x = 42;  // unused variable
    int y = 42;
    if (y = 5) {
        std::cout << y << '\n';
    }
    unsused_param("Hello");
    int z = 1.2;
    std::cout << z << '\n';
    int len = 3;
    int vla[len];
}
constexpr std::string_view current_compiler() {
#if defined(__clang__)
    return "Clang";
#elif defined(__GNUC__)
    return "GCC";
#elif defined(_MSC_VER)
    return "MSVC";
#else
    return "Unknown compiler";
#endif
}

void test_demangling() {
    auto x = std::vector<int>{};

    const char* mangled = typeid(x).name();

    if (current_compiler() == "GCC") {
        int status;
        char* demangled = abi::__cxa_demangle(mangled, nullptr, nullptr, &status);

        if (status == 0 && demangled)
            std::cout << "Typ: " << demangled << '\n';
        free(demangled);
    }
    else {
        std::cout << "Typ (mangled): " << mangled << '\n';
    }


}



int main() {
    std::cout << "Hello Modern C++!" << std::endl;
    //test_variables();
    //test_for_loops();
    //test_compiler_options();
    test_demangling();


    return 0;
}
