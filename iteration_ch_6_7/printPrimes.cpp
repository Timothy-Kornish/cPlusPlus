#include <iostream>

int main() {
  int maxValue;

  std::cout << "Display primes up to what number? ";
  std::cin >> maxValue;
  int value = 2;

  while (value <= maxValue) {
    bool isPrime = true;
    int trialFactor = 2;

    while (trialFactor < value) {
      if (value % trialFactor == 0){
        isPrime = false;
        break;
      }
      trialFactor++;
    }
    if (isPrime) {
      std::cout << value << " ";
    }
    value++;
  }
  std::cout << '\n';
}
