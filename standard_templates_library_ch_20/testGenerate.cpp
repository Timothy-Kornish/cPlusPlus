#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include "uniformrandom.h"

int main() {
  std::vector<int> nums(20);
  UniformRandomGenerator gen(0, 100);

  auto output = std::ostream_iterator<int>(std::cout, " ");

  std::generate(std::begin(nums), std::end(nums), []() { return 2; });
  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << "\n-------------------------------------\n";

  int i = 10;
  std::generate(std::begin(nums), std::end(nums), [&i]() {
                                                    int result = i;
                                                    if (i % 10 == 0) {
                                                      i += 5;
                                                    }
                                                    else {
                                                      i++;
                                                    }
                                                    return result;
                                                  });
  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << "\n-------------------------------------\n";

  std::generate(std::begin(nums), std::end(nums), gen);
  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << "\n-------------------------------------\n";

}
