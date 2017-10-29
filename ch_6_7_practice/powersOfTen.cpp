#include <iostream>
#include <iomanip>

int main() {
  int power = 1;
  while (power <= 1000000000) {
    std::cout << std::setw(10) << power << '\n';
    power *= 10;
  }
}
