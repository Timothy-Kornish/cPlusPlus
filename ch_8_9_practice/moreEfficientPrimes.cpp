#include <iostream>
#include <cmath>

int main() {
  int max;
  std::cout << "Display primes up to what value? ";
  std::cin >> max;
  for (int value = 2; value <= max; value++){
    bool isPrime = true;
    double r = value, root = sqrt(r);
    for (int factor = 2; isPrime && factor <= root; factor++){
      isPrime = (value % factor !=0);
    }
    if (isPrime){
      std::cout << value << " ";
    }
  }
  std::cout << '\n';
}
