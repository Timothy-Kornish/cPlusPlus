#include <iostream>
#include <cstdlib>

int main() {
  srand(23);
  for (int i = 0; i < 10; i++) {
    int r = rand();
    std::cout << r << '\n';
  }
  std::cout << '\n';
}
