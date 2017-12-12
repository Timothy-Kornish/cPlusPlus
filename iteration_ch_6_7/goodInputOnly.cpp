#include <iostream>

int main() {
  int input = -1;
  std::cout << "Please enter an integer in the range 0-10: ";

  while (input < 0 || input > 10) {
    std::cin >> input;

  }
  std::cout << "Legal value was entered " << input << '\n';
}
