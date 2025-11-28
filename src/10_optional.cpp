#include <iostream>
#include <string>
#include <optional>
std::optional<int> asInt(const std::string& s) // returns int or "no int"
{
    try {
        return std::stoi(s);
    }
    catch (...) {
        return {};
    }
}

int main()
{
    for (auto s : {"42", " 077", "hello", "0x33"} ) {
        std::optional<int> oi = asInt(s);
        if (oi) {
            std::cout << "convert '" << s << "' to int: " << *oi << "\n"; // int
        }
        else {
            std::cout << "can't convert '" << s << "' to int\n"; // "no int"
        }
    }
}