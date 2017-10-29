#include <iostream>

int main() {
  int val1, val2, sum;
  std::cout << "Please enter two integers: " << std::endl;
  std::cin >> val1 >> val2;
  sum = val1 + val2;
  std::cout << val1 << " + " << val2 << " = " << sum << std::endl;
}
