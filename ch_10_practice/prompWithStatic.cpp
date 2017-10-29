#include <iostream>

int prompt() {
  static int count = 0;
  int value;
  std::cout << "Please enter integer #" << ++count << ": ";
  std::cin >> value;
  return value;
}

int main() {
  int value1, value2, sum;
  std::cout << "This program adds two integers.\n";
  value1 = prompt();
  value2 = prompt();
  sum = value1 + value2;
  std::cout << value1 << " + " << value2 << " = " << sum << std::endl;
}
