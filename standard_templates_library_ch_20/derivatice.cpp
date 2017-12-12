#include <iostream>
#include <iomanip>
#include <functional>

std::function<double(double)> derivative(std::function<double(double)> f, double h) {
  return [f, h] (double x) { return (f(x + h) - f(x)) / h; };
}

double fun(double x) {
  return 3 * x * x + 5;
}

double ans(double x) {
  return 6 * x;
}

int main() {
  double h = 0.0000001;
  auto der = derivative(fun, h);
  double x = 5.0;
     std::cout << "-------------------------------------------------\n";
     std::cout << "                            Approx.    Actual \n";
     std::cout << "   x       f(x)      h      f\'(x)      f\'(x)\n";
     std::cout << "-------------------------------------------------\n";
     while (x < 5.1) {
       std::cout << std::fixed << std::showpoint << std::setprecision(5);
       std::cout << x << " " << fun(x) << " " << h << " " << der(x)
                 << "   " << ans(x) << '\n';
       x += 0.01;
     }
}
