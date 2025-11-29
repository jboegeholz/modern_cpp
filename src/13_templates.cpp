#include <iostream>
#include <vector>

template<typename T>
constexpr T max(const T& a, const T& b) {
  return a > b ? a : b;
}
int main() {

  std::cout << max(1, 2) << '\n';
  std::cout << max(1.0F, 2.0F) << '\n';
  std::cout << max(1.0, 2.0) << '\n';
  std::vector<float> float_numbers = {-3.5, 1.0, -2.0, -11.0};
  std::vector<int> int_numbers = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto descending = []<typename T>(const T a, const T b) {
    return a > b;
  };
  std::sort(float_numbers.begin(), float_numbers.end(), descending);
  std::sort(int_numbers.begin(), int_numbers.end(), descending);
}