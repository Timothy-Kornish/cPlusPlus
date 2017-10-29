#include <iostream>

int main() {
  int value;
  std::cout << "please enter an integer in the range from 0 to 10: ";
  std::cin >> value;

  if (value >= 0){
    if (value <= 10){
      std::cout << "in range" << std::endl;
    } else {
      std::cout << "Too large" << std::endl;
    }
  } else {
    std::cout << "Too low" << std::endl;
  }
}
