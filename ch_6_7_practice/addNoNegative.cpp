#include <iostream>

int main() {
  int input;
  int sum = 0;

  std::cout << "Enter numbers to sum, type 'q' ends list: ";

  while (std::cin >> input) {
    sum += input;
  }
  std::cout << "Sum = " << sum << '\n';
}
