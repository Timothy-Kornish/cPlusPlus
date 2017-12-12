#include <iostream>
#include "rectangle.h"

class DrawableRectangle: public Rectangle {
public:
  DrawableRectangle(double length, double width): Rectangle(length, width) {}

  void draw() const {
    int rows = static_cast<int>(length + 0.5);
    int columns = static_cast<int>(width + 0.5);

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c< columns; c++) {
        std::cout << '#';
      }
      std::cout << '\n';
    }
  }
};

int main() {
  DrawableRectangle rec1(3, 2), rec2(10, 5), rec3(4, 8);

  rec1.draw();
  std::cout << "----------------\n";
  rec2.draw();
  std::cout << "----------------\n";
  rec3.draw();

}
