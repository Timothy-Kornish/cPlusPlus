#include <iostream>
#include <iomanip>

int main() {

  int size;
  std::cout << "Please enter the table size: ";
  std::cin >> size;

  std::cout << "    ";
  int column = 1;
  while (column <= size) {
    std::cout << std::setw(4) << column;
    column++;
  }
  std::cout << '\n';

  std::cout << "   * ";
  column = 1;
  while (column <= size) {
    std::cout << "----";
    column++;
  }
  std::cout << '\n';

  int row = 1;
  while (row <= size) {
    std::cout << std::setw(2) << row << " |";
    column = 1;
    while (column <= size) {
      int product = column * row;
      std::cout << std::setw(4) << product;
      column++;
    }
    row++;
    std::cout << '\n';
  }
}
