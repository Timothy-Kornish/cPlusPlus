#include <iostream>
#include <cmath>

bool isPrime(int n) {
  bool result = true;
  double r = n, root = sqrt(r);

  for (int trialFactor = 2; result && trialFactor <= root; trialFactor++) {
    result = (n % trialFactor != 0);
  }
  return result;
}

int main() {
  int maxValue;
  std::cout << "Display primes up to what value: ";
  std::cin >> maxValue;

  for (int value = 2; value <= maxValue; value++) {
    if (isPrime(value)) {
      std::cout << value << " ";
    }
  }
  std::cout << '\n';
}
