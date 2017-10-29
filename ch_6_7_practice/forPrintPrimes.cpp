#include <iostream>

int main() {

  int maxValue;
  std::cout << "Display primes up to what value? ";
  std::cin >> maxValue;

  for (int value = 2; value <= maxValue; value++){
    bool isPrime = true;

    for (int trialFactor = 2; trialFactor < value; trialFactor++){
      isPrime = (value % trialFactor != 0);
      if (!isPrime){
        break;
      }
    }

    if(isPrime) {
      std::cout << value << " ";
    }
  }
  std::cout << '\n';
}
