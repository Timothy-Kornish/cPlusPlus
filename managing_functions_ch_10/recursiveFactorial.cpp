#include <iostream>

int factorial(int n=10) {
  if(n==0){
    return 1;
  }
  else {
    return n * factorial(n-1);
  }
}

int main() {
  std::cout << " 0! = " << factorial(0) << '\n';
  std::cout << " 1! = " << factorial(1) << '\n';
  std::cout << " 2! = " << factorial(2) << '\n';
  std::cout << " 5! = " << factorial(5) << '\n';
  std::cout << " 10! = " << factorial(10) << '\n';
}
