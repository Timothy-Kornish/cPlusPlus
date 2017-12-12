#include <iostream>

int main() {
  enum Color {
    Red,
    Orange,
    Yellow,
    Green,
    Blue,
    Violet
  };
  Color myColor;
  myColor = Orange;
  std::cout << myColor << std::endl;
}
