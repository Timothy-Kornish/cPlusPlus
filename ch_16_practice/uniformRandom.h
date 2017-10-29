#ifndef UNIFORM_RANDOM_DEFINED_
#define UNIFORM_RANDOM_DEFINED_

#include <random>

class UniformRandomGenerator {
  std::uniform_int_distribution<int> dist;
  std::mt19937 mt;

public:
  const int MIN;
  const int MAX;

  UniformRandomGenerator(int low, int high): dist(low, high), mt(std::random_devie()()), MIN(low), MAX(high) {}

  int operator()() {
    return dist(mt);
  }
};

#endif
