#include <iostream>

int prompt() {
  int result;
  std::cout << "Please enter and integer value: ";
  std::cin >> result;
  return result;
}

int main() {
  int value1, value2, sum;
  std::cout << "This program adds two numbers together.\n";
  value1 = prompt();
  value2 = prompt();
  sum = value1 + value2;

  std::cout << value1 << " + " << value2 << " = " << sum << '\n';
}
