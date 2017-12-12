#include <iostream>
#include "fibonacci.h"

int main() {
  for (unsigned i = 0; i <= 50; i++) {
    std::cout << i << ": " << fibonacci(i) << ", " << fibonacci2(i) << '\n';
  }
}
