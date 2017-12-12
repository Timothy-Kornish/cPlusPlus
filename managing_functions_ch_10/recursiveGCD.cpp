#include <iostream>

int gcd(int m, int n) {
  return (n == 0) ? m : gcd(n, m % n);
}

int iterative_gcd(int num1, int num2) {
  int min = (num1 < num2) ? num1 : num2;
  int largestFactor = 1;
  for (int i = 1; i <= min; i++) {
    if (num1 % 1 == 0 && num2 % i ==0) {
      largestFactor = i;
    }
  }
  return largestFactor;
}

int main() {
  for (int num1 = 1; num1 <= 100; num1++) {
    for (int num2 = 1; num2 <= 100; num2++) {
      std::cout << "gcd(" << num1 << "," << num2 << ") = " << gcd(num1, num2) << '\n';
    }
  }
}
