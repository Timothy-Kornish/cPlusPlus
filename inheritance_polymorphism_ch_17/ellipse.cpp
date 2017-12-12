#include "ellipse.h"
#include <algorithm>

static const double PI = 3.14159;

Ellipse::Ellipse(double major, double minor):
  major_radius(major), minor_radius(minor) {}

double Ellipse::span() const {
  return std::max(major_radius, minor_radius);
}

double Ellipse::area() const {
  return PI * major_radius * minor_radius;
}
