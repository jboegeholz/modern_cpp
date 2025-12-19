#include <iostream>

int __fastcall add1(int x, int y)
{
    return x + y;
}
int __cdecl add2(int x, int y)
{
    return x + y;
}
int __thiscall add3(int x, int y)
{
    return x + y;
}


int main()
{
    int c = add1(2,4);
    std::cout << c;
}
