#include <iostream>

int main() {
  bool a = true, b = false;

  std::cout << "a = " << a << ", b = " << b << '\n';
  a = false;
  std::cout << "a = " << a << ", b = " << b << '\n';
  a = 1;
  b = 1;
  std::cout << "a = " << a << ", b = " << b << '\n';
}
