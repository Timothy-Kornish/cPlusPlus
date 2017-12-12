#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

const int MAX = 2000000; // 2,000,000

std::vector<bool> nonprimes(MAX);

void countPrimes1() {
  int count = 0;
  clock_t start_time = clock();
  for (int value = 2; value <= MAX; value++) {
    bool isPrime = true;

    for (int trialFactor = 2; isPrime && trialFactor < value; trialFactor++) {
      isPrime = (value % trialFactor != 0);
    }
    if (isPrime){
      count++;
    }
  }
  std::cout << "Count = " << count << "  ";
  std::cout << "Elapsed time: "
            << static_cast<double>(clock() - start_time)/CLOCKS_PER_SEC << " seconds\n";
}

void countPrimes2() {
    int count = 0;
    clock_t start_time = clock();   // Record start time
    for (int value = 2; value <= MAX; value++) {
        // See if value is prime
        bool is_prime = true;  // Provisionally, value is prime
        double r = value, root = sqrt(r);
        // Try all possible factors from 2 to the square
        // root of value
        for (int trial_factor = 2; is_prime && trial_factor <= root; trial_factor++) {
            is_prime = (value % trial_factor != 0);
          }
        if (is_prime) {
            count++;  // Count the prime number
          }
    }
    // Print the elapsed time
    std::cout << "Count = " << count << "  ";
    std::cout << "Elapsed time: "
              << static_cast<double>(clock() - start_time)/CLOCKS_PER_SEC
              << " seconds\n";
}

void countPrimes3() {
  int count = 0;
  clock_t start_time = clock();

  nonprimes[0] = nonprimes[1] = true;

  for (int i = 2; i < MAX; i++) {
        // See if i is prime
        if (!nonprimes[i])  {
            count++;  // It's prime, so count it
            // It is prime, so eliminate all of its
            // multiples that cannot be prime
            for (int j = 2*i; j < MAX; j += i) {
              nonprimes[j] = true;
            }
        }
    }
  // Print the elapsed time
  std::cout << "Count = " << count << "  ";
  std::cout << "Elapsed time: "
            << static_cast<double>(clock() - start_time)/CLOCKS_PER_SEC
            << " seconds\n";

}

int main() {
  countPrimes1();
  countPrimes2();
  countPrimes3();
}
