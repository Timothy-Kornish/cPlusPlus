#include <iostream>
#include <iomanip>
#include <cmath>

double squareRoot(double value) {
  double difference, root = 1.0;

  do {
    root = ( root + value/root) / 2.0;

    difference = root * root - value;
  } while (std::abs(difference) > 0.0001 );
  return root;
}

int main() {
  for (double d = 1.0; d <=10.0; d+= 0.5){
    std::cout << std::setw(7) << squareRoot(d) << " : " << sqrt(d) << '\n';
  }
}
