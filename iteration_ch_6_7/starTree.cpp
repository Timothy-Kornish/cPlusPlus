#include <iostream>

int main() {
  int height, row = 0;
  std::cout << "Enter the height of the tree: ";
  std::cin >> height;

  while (row < height) {

    int count = 0;
    while(count < height - row) {
      std::cout << " ";
      count++;
    }

    count = 0;
    while(count < 2*row + 1) {
      std::cout << "*";
      count++;
    }
    std::cout << '\n';
    row++;
  }
}
