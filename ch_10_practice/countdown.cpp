#include <iostream>

void countdown(int n=10) { // default parameter of 10
  while(n > 0) {
    std::cout << n-- << '\n';
  }
}

int main() {
  countdown(5); // use specific parameter
  std::cout << "------------\n";
  countdown(); // use default parameter
}
