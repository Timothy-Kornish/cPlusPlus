#include <iostream>

int main() {
  int value;

  std::cout << "Please enter an integer in the range 0 to 5: ";
  std::cin >> value;

  switch(value) {
    case 0:
      std::cout << "Zero";
      break;
    case 1:
      std::cout << "One";
      break;
    case 2:
      std::cout << "Two";
      break;
    case 3:
      std::cout << "Three";
      break;
    case 4:
      std::cout << "Four";
      break;
    case 5:
      std::cout << "Five";
      break;
    default:
      if(value < 0){
        std::cout << "Too small";
      } else {
        std::cout << "Too Large";
      }
      break;
  }
  std::cout << '\n';
}
