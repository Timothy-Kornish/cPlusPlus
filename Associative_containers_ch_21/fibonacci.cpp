#include <unordered_map>
#include "fibonacci.h"

Integer fibonacci(unsigned n) {
  if (n <= 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    return fibonacci(n - 2) + fibonacci(n - 1);
  }
}

Integer fibonacci2(unsigned n) {
  static std::unordered_map<unsigned, Integer> ans {{0,0}, {1,1}};
  if (n > 1 && ans[n] == 0) {
    ans[n] = fibonacci2(n - 2) + fibonacci2(n - 1);
  }
  return ans[n];
}
