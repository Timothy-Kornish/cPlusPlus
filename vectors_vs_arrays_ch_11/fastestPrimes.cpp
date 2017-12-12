#include <iostream>
#include <vector>
#include <ctime>

const int MAX = 500;

std::vector<bool> nonPrimes(MAX);

int main() {
  clock_t startTime = clock();

  nonPrimes[0] = nonPrimes[1] = true;

  for (int i = 2; i < MAX; i++) {
    if (!nonPrimes[i]) {
      std::cout << i << " ";

      for (int j = 2*i; j < MAX; j += i) {
        nonPrimes[j] = true;
      }
    }
  }

  std::cout << '\n';

  std::cout << "Elapsed time: " << static_cast<double>(clock() - startTime)/CLOCKS_PER_SEC
            << " seconds\n";
}
