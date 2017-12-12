#include <iostream>
#include <iomanip> // allows for std::setprecision

int main() {
  double d1 = 2000.5, d2 = 2000.0;
  std::cout << std::setprecision(16) << (d1 - d2) << '\n';
  double d3 = 2000.58, d4 = 2000.0;
  std::cout << std::setprecision(16) << (d3 - d4) << '\n';
}
