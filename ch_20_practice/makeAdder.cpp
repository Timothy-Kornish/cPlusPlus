#include <iostream>
#include <functional>

std::function<int(int)> make_adder() {
  int local_val = 2;
  return [local_val](int x)->int { return x + local_val; };
}

int main() {
  auto f = make_adder();
  std::cout << f(10) << '\n';
  std::cout << f(2) << '\n';
}
