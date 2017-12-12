#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  srand(static_cast<unsigned>(time(0)));

  for (int i = 0; i < 100; i++) {
    int r = rand();
    std::cout << (r % 20) << '\n'; // include 0 but not 20, 0 indexed
  }
  std::cout << '\n';
}
