#include <iostream>
#include <cmath>

int main() {
  double x;
  double y;

  const double PI = 3.14159;
  const double p_x = 100;
  const double p_y = 0;

  const double radians = 10 * PI/180;
  const double COS10 = cos(radians);
  const double SIN10 = sin(radians);

  std::cout << "Enter intital satellite coordinates (x,y): ";
  std::cin >> x >> y;

  double d1 = sqrt((p_x - x)  * (p_x - x) + (p_y - y) * (p_y - y));

  double x_old = x;
  x = x * COS10 - y * SIN10;

  y = x_old * SIN10 + y * COS10;

  double d2 = sqrt((p_x - x) * (p_x - x) + (p_y - y) * (p_y -y));

  std::cout << "Difference in distances: " << d2 - d1 << '\n';


}
