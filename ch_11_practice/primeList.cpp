#include <iostream>
#include <vector>
#include <cmath>

void print(const std::vector<int>& v) {
  for (int elem : v) {
    std::cout << elem << '\n';
  }
  std::cout << '\n';
}

bool isPrime(int n) {
  if (n < 2) {
    return false;
  } else {
    bool result = true;
    double r = n, root = sqrt(r);

    for (int trialFactor = 2; result && trialFactor <= root; trialFactor++) {
      result = (n % trialFactor != 0);
    }
    return result;
  }
}

std::vector<int> primes(int begin, int end) {
  std::vector<int> result;
  for (int i = begin; i <= end; i++) {
    if (isPrime(i)) {
      result.push_back(i);
    }
  }
  return result;
}

int main() {
  int low, high;
  std::cout << "Please enter lowest and highest value in the range: ";
  std::cin >> low >> high;
  std::vector<int> primeList = primes(low, high);
  print(primeList);
}
