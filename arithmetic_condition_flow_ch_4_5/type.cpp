#include <iostream>

int main() {
  double x = 1.23;
  int i;
  i = static_cast<int>(x);
  int j = static_cast<double>(i);
  std::cout <<  "i = " << i << " , x = "<< x << " , j = "<< j<< std::endl;

}
