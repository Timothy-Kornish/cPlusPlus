#include <iostream>
#include <cmath>

int main() {
  double input;
  std::cout << "Enter number: ";
  std::cin >> input;

  double root = sqrt(input);

  std::cout << "Square root of " << input << " = " << root << std::endl;
}
