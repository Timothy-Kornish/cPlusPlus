#include <iostream>

int main() {
  int num1, num2;
  std::cout << "Please enter two integers: ";
  std::cin >> num1 >> num2;

  int min = (num1 < num2) ? num1 : num2;
  int largestFactor = 1;

  for (int i = 2; i <= min; i++) {
    if (num1 % i == 0 && num2 % i == 0) {
      largestFactor = i;
    }
  }
  std::cout << largestFactor << '\n';
}
