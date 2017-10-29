#include <iostream>

int main() {
  int x = 5;
  int y = x;
  int& r = x;

  std::cout << "x = " << x << '\n';
  std::cout << "y = " << y << '\n';
  std::cout << "r = " << r << '\n';
  std::cout << "Assign x to 7\n";
  x = 7;
  std::cout << "x = " << x << '\n';
  std::cout << "y = " << y << '\n';
  std::cout << "r = " << r << '\n';
  std::cout << "Assign y to 8\n";
  y = 8;
  std::cout << "x = " << x << '\n';
  std::cout << "y = " << y << '\n';
  std::cout << "r = " << r << '\n';
  std::cout << "Assign r to 2\n";
  r = 2;
  std::cout << "x = " << x << '\n';
  std::cout << "y = " << y << '\n';
  std::cout << "r = " << r << '\n';
}
