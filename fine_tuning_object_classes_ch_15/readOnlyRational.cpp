#include <iostream>
#include <cstdlib>

class ReadOnlyRational {
  int numerator;
  int denominator;
public:
  ReadOnlyRational(int n, int d): numerator(n), denominator(d) {
    if (d == 0) {
      std::cout << "Zero denominator error\n";
      exit(1);
    }
  }

  ReadOnlyRational(): numerator(0), denominator(1) {}

  int get_numerator() const {
    return numerator;
  }

  int get_denominator() const {
    return denominator;
  }
};

std::ostream& operator<<(std::ostream& os, const ReadOnlyRational& f) {
  os << f.get_numerator() << '/' << f.get_denominator();
  return os;
}

int main() {
  ReadOnlyRational fract1(1, 2);
  std::cout << "The fraction is " << fract1 << '\n';
  ReadOnlyRational fract2(2, 3);
  std::cout << "The fraction is " << fract2 << '\n';
}
