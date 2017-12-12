#include <iostream>
#include <cmath>

int main() {
  double x = 16.0;

  std::cout << sqrt(16.0) << '\n';
  std::cout << sqrt(x) << '\n';
  std::cout << sqrt(2 * x - 5) << '\n';
  double y = sqrt(x);

  y = 2 * sqrt(x + 16) - 4;

  y = sqrt(sqrt(256.0));
  std::cout << y << '\n';
}
