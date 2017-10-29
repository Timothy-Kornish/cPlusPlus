#include <iostream>

int main() {
  int input, row = 1;
  std::cout << "Please enter a positive integer: ";
  std::cin >> input;

  while (row <= input) {
    int column = 1;
    while (column <= input) {
      std::cout << "*";
      column++;
    }
    std::cout << '\n';
    row++;
  }
  std::cout << '\n';
}
