#include <chrono>
#include <iostream>

int main()
{
    std::cout << "Hello Move Semantics" << std::endl;


    //std::string a = "Hallo"; -> SSO
    std::string a = std::string(1000, 'x');
    std::cout << "a.data(): " << static_cast<const void*>(a.data()) << '\n';
    std::string b = a;
    std::string c = std::move(a);
    std::cout << "b.data(): " << static_cast<const void*>(b.data()) << '\n';
    std::cout << "c.data(): " << static_cast<const void*>(c.data()) << '\n';

}