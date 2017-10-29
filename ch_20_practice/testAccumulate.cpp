#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <random>

#include "uniformrandom.h"

int main() {
  std::vector<int> nums(6);

  UniformRandomGenerator gen(1, 5);

  auto output = std::ostream_iterator<int>(std::cout, " ");

  std::generate(std::begin(nums), std::end(nums), gen);
  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << "\n-------------------------------------\n";

  std::cout << std::accumulate(std::begin(nums), std::end(nums), 0,
               [](int a, int b) { return a + b; }) << '\n';

  std::cout << std::accumulate(std::begin(nums), std::end(nums), 1,
               [](int a, int b) { return a * b; }) << '\n';
}
