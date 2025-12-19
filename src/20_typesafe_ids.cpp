// http://www.sevangelatos.com/type-safe-identifiers-in-c/
#include <cassert>
#include <iostream>
#include <map>
#include <string>

template <typename T>
class TypeSafeIdentifier {
public:
    explicit TypeSafeIdentifier(int id = 0) : id_(id) {}

    [[nodiscard]] int value() const noexcept { return id_; }

    bool operator<(TypeSafeIdentifier<T> rhs) const noexcept;
    bool operator==(TypeSafeIdentifier<T> rhs) const noexcept;
    bool operator!=(TypeSafeIdentifier<T> rhs) const noexcept;
    friend std::ostream& operator<<(const std::ostream& lhs, const T& rhs)
    {
        return rhs.id;
    }

private:
    int id_;
};


class Customer;
using CustomerId = TypeSafeIdentifier<Customer>;

class Comment;
using CommentId = TypeSafeIdentifier<Comment>;



int main() {
    CustomerId minty(1);
    CommentId lassy(1);
    CommentId spot(2);


    std::map<CommentId, std::string> dog_names = {{lassy, "Lassy"}, {spot, "Spot"}};


    for (const auto& it : dog_names) {
        std::cout << it.second << "'s DogId is " << it.first << std::endl;
    }
}
