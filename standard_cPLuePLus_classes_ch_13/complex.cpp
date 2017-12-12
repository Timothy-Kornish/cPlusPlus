#include <iostream>
#include <complex>

double complex_quadratic(double x1, double x2, double y1, double y2) {
  return ((x1 * x2) + (y1 * x2) + (x1 * y2) - (y1 * y2));
}

int main() {

  std::complex<double> c1(2.0, 3.0), c2(2.0, -3.0);

  double real1 = c1.real(), real2 = c2.real();
  double imag1 = c1.imag(), imag2 = c2.imag();

  std::cout << c1 << " * " << c2 << " = "
            << complex_quadratic(real1, real2, imag1, imag2) << '\n';
  std::cout << c1 << " * " << c2 << " = "<< (c1 * c2) << '\n';
}
