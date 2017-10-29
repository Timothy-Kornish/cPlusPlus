#include <iostream>

int main() {
  int dividend, divisor, quotient, remain;

  std::cout << "please enter two integers to be divided: ";
  std::cin >> dividend >> divisor;

  if (divisor != 0) {
    quotient = dividend / divisor;
    remain = dividend % divisor;

    std::cout << dividend << " divided by " << divisor << " is "
              << quotient << " with remainder " << remain << '\n';
  }
  else {
    std::cout << "Division by 0 is not allowed\n";
  }
}
