#include <iostream>
#include <string>
#include <optional>
std::optional<int> asInt(const std::string& s) // returns int or "no int"
{
    try {
        return std::stoi(s);
    }
    catch (...) {
        return {};  // return std::nullopt;
    }
}

int main()
{
    for (const auto s : {"42", " 077", "hello", "0x33"} ) {
        if (std::optional<int> oi = asInt(s)) {
            std::cout << "convert '" << s << "' to int: " << *oi << "\n"; // int
        }
        else {
            std::cout << "can't convert '" << s << "' to int\n"; // "no int"
        }
    }
}