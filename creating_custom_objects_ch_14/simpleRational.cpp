#include <iostream>
#include <cstdlib>

class SimpleRational {
  int numerator;
  int denominator;

public:

  SimpleRational(int n, int d): numerator(n), denominator(d) {
    if (d == 0) {
      std::cout << "Zero denominator error\n";
      exit(1);
    }
  }

  SimpleRational(): numerator(0), denominator(1) {} // default parameter constructor
  // user for:  SimpleRational frac;
  // without the params like: SimpleRational frac(1, 2);

  void set_numerator(int n) {
    numerator = n;
  }

  void set_denominator(int d) {
    if (d != 0) {
      denominator = d;
    }
    else {
      std::cout << "Zero denominator error\n";
      exit(1);
    }
  }

  int get_numerator() {
    return numerator;
  }

  int get_denominator() {
    return denominator;
  }
};

SimpleRational multiply(const SimpleRational& f1, const SimpleRational& f2) {
  SimpleRational f3;
  f3.set_numerator(f1.get_numerator() * f2.get_numerator());
  f3.set_denominator(f1.get_denominator() * f2.get_denominator());
  return  f3;
}

void print_fraction(const SimpleRational&  f) {
  std::cout << f.get_numerator() << "/" << f.get_denominator();
}

int main() {
  SimpleRational fract(1, 2);
  std::cout << "The fraction is ";
  print_fraction(fract);
  std::cout << '\n';
  fract.set_numerator(19);
  fract.set_denominator(4);
  std::cout << "The fraction is now: ";
  print_fraction(fract);
  std::cout << '\n';

  SimpleRational fract1(1, 2), fract2(2, 3);
  auto prod = multiply(fract1, fract2);
  std::cout << "The product of ";
  print_fraction(fract1);
  std::cout << " and ";
  print_fraction(fract2);
  std::cout << " is ";
  print_fraction(prod);
  std::cout << '\n';
}
