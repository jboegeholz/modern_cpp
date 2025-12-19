#include <iostream>


class Mumbo
{
public:
    explicit Mumbo(const int id): id(id)
    {

    }
    [[nodiscard]] int get_Value() const
    {
        return id;
    }
    friend std::ostream& operator<<(std::ostream& lhs, const Mumbo& rhs)
    {
        return lhs << rhs.id;
    }
private:
    int id = 0;
};

int main()
{
    const Mumbo mumbo(42);
    std::cout << mumbo << std::endl;
}
