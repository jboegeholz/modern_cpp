#include <iostream>
#include <future>

int worker_function(const int input)
{
    return input * 2;
}

int main(){

    int input = 1;

    auto handle = std::async(std::launch::async, worker_function, input);
    auto result = handle.get();
    std::cout << "Result: " << result << std::endl;
    return 0;
}