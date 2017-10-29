#include <iostream>
#include <cstdlib>

class PrintOnlyRational {
  int numerator;
  int denominator;
public:
  PrintOnlyRational(int n, int d): numerator(n), denominator(d) {
    if (d == 0) {
      std::cout << "Zero denominator error\n";
      exit(1);
    }
  }
  PrintOnlyRational(): numerator(0), denominator(1) {}

  friend std::ostream& operator<<(std::ostream& os, const PrintOnlyRational& f);
};

std::ostream& operator<<(std::ostream& os, const PrintOnlyRational& f) {
  os << f.numerator << '/' << f.denominator;
  return os;
}

int main() {
  PrintOnlyRational fract(1, 2);
  std::cout << "The fraction is " << fract << '\n';
  PrintOnlyRational fract2(2, 3);
  std::cout << "The fraction is " << fract2 << '\n';
}
