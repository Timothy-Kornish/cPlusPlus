#include <iostream>

int main() {
  int input;
  std::cout << "Please enter an integer in the range 0-10: ";

  do {
    std::cin >> input;
  } while(input < 0 || input >10);
  std::cout << "Legal value entered was " << input << '\n';
}
