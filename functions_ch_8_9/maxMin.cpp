#include <iostream>
#include <algorithm>

int main() {
  int val1, val2;
  std::cout << "Please enter two interger values: ";
  std::cin >> val1 >> val2;
  std::cout << "Max = " << std::max(val1, val2) << ", Min = " << std::min(val1,val2) << '\n';
}
