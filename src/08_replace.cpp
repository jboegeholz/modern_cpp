#include <cassert>
#include <string>

int main() {
    std::string str = "IIII";

    const size_t index = str.find("IIII");
    str.replace(index, str.size(), "IV");
    assert (str == "IV");
}
