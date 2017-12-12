#include <iostream>
#include <ctime>
#include <functional>

#include "fibonacci.h"

unsigned time_it(const std::function<Integer(unsigned)>& f, unsigned n) {
  clock_t start_time = clock();
  f(n);
  clock_t end_time = clock();
  return static_cast<unsigned>(end_time - start_time);
}

int main() {
  auto t1 = time_it(fibonacci, 43);
  auto t2 = time_it(fibonacci2, 43);
  std::cout << "Time: " << "fibonacci = "<< t1 << " msec, fibonacci2 = "
  << t2 << " msec\n";
}
