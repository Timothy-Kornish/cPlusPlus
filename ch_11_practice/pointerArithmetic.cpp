#include <iostream>

int main() {
  int arr[] = {10, 20, 30, 40, 50};
  int *p = arr;
  std::cout << "*p   = " << *p << '\n';
  std::cout << "p[0] = " << p[0] << '\n';
  std::cout << "p[1] = " << p[1] << '\n';
  std::cout << "*p   = " << *p << '\n';
  p++;
  std::cout << "after p++: *p   = " << *p << '\n';
  p += 2;
  std::cout << "after p+= 2: *p   = " << *p << '\n';
  std::cout << "p[0] = " << p[0] << '\n';
  std::cout << "p[1] = " << p[1] << '\n';
  p--;
  std::cout << " after p--: *p   = " << *p << '\n';

}
