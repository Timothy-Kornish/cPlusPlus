#include <iostream>
#include <iomanip>

int main() {
  int size, row = 1;
  std::cout << "Please enter a table size: ";
  std::cin >> size;

  while (row <= size) {
    int column = 1;

    while (column <= size) {
      int product = row * column;
      std::cout << std::setw(4) << product;
      column++;
    }
    std::cout << '\n';
    row++;
  }

}
