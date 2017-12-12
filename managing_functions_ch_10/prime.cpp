#include <cmath>
#include "prime.h"

bool isPrime(int n) {
  bool result = true;
  double r = n, root = sqrt(r);

  for(int trialFactor = 2; trialFactor <= root && result; trialFactor++) {
    result = (n % trialFactor != 0);
  }
  return result;
}
