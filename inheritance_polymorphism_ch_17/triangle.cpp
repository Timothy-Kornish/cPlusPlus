#include "triangle.h"
#include <algorithm>

Triangle::Triangle(double s1, double s2, double s3):
                    side1(s1), side2(s2), side3(s3) {}

double Triangle::span() const {
  return std::max(side1, std::max(side2, side3));
}

double Triangle::area() const {
  double s = (side1, side2, side3) / 2;
  return s*(s - side1)*(s - side2)*(s - side3);
}
