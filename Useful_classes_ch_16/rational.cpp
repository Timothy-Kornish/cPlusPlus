#include <iostream>

class Rational {
  int numerator;
  int denominator;

  static int gcd(int m, int n) {
    if (n == 0) {
      return 0;
    }
    else {
      return gcd(n, m % n);
    }
  }

  static int lcm(int m, int n) {
    return static_cast<int>(m * n / gcd(m, n));
  }

public:
  Rational(int n, int d): numerator(n), denominator(d) {
    if (d == 0) {
      std::cout << "*****Warning---Illegal Rational\n";
      numerator = 0;
      denominator = 1;
    }
  }
  Rational(): numerator(0), denominator(1) {}

  int get_numerator() const {
    return numerator;
  }

  int get_denominator() const {
    return denominator;
  }

  Rational reduce() const {
    int factor = gcd(numerator, denominator);
    Rational rat(numerator/factor, denominator/factor);
    return rat;
  }

  bool operator==(const Rational& fract) const {
    Rational f1 = reduce(), f2 = fract.reduce();
    return ((f1.numerator == f2.numerator) && (f1.denominator == f2.denominator));
  }

  bool operator!=(const Rational& other) {
    return !(*this == other);
  }

  Rational operator+(const Rational& fract) const {
    int commonDenominator = lcm(denominator, fract.denominator);
    int newNumerator = ((numerator * commonDenominator / denominator)
        + (fract.numerator * commonDenominator / fract.denominator));
    Rational rat(newNumerator, commonDenominator);
    return rat;
  }

  Rational operator*(const Rational& fract) const {
   Rational rat(numerator * fract.numerator, denominator * fract.denominator);
   return rat.reduce();
  }
};

std::ostream& operator<<(std::ostream& os, const Rational& r) {
  os << r.get_numerator() << '/' << r.get_denominator();
  return os;
}

int main() {
  Rational f1(1, 2), f2(1, 3);
  std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
  std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
}
