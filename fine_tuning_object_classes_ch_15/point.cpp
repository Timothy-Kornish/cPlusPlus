#include <iostream>
#include <cmath>

class Point {
  double x;
  double y;
public:
  Point(double x, double y): x(x), y(y) {}

  double get_x() const {
    return x;
  }
  double get_y() const {
    return y;
  }
  void set_x(double x) {
    this->x = x;
  }
  void set_y(double y) {
    this->y = y;
  }
};

double dist(const Point& pt1, const Point pt2) {
  double distance = sqrt((pt1.get_x() - pt2.get_x()) * (pt1.get_x() - pt2.get_x()) +
                     (pt1.get_y() - pt2.get_y()) * (pt1.get_y() - pt2.get_y()));
  return distance;
}

int main() {
    Point p1(2.5, 6), p2(0.0, 0.0);
    std::cout << dist(p1, p2) << '\n';
}
