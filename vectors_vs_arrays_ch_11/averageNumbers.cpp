#include <iostream>

int main() {
  double n1, n2, n3, n4, n5;

  std::cout << "Please enter 5 numbers: ";
  std::cin >> n1 >> n2 >> n3 >> n4 >> n5;
  std::cout << "The average number of " << n1 << ", " << n2 << ", "
            << n3 << ", " << n4 << ", " << n5 << " is "
            << (n1 + n2 + n3 + n4 + n5)/5 << '\n';
}
