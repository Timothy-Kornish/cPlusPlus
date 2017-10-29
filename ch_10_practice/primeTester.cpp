#include <iostream>
#include "prime.h"

// to complile in terminal: g++ primeTester.cpp prime.cpp
// both files at once.
// otherwise isPrime(value) will error
int main() {
  int maxValue;
  std::cout << "Display primes up to what number? ";
  std::cin >> maxValue;
  for (int value = 2; value <= maxValue; value++) {
    if (isPrime(value)) {
      std::cout << value << " ";
    }
  }
  std::cout << '\n';
}
