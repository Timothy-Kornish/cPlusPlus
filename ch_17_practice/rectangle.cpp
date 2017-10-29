#include "rectangle.h"
#include <algorithm> // for max function

Rectangle::Rectangle(double length, double width): length(length), width(width) {}

double Rectangle::span() const {
  return std::max(length, width);
}

double Rectangle::area() const {
  return length * width;
}
