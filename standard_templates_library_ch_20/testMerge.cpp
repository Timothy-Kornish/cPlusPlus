#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

#include "uniformrandom.h"

int main() {
  std::vector<int> num1(15), num2(13);

  UniformRandomGenerator gen1(0,40), gen2(0, 40);

  auto output = std::ostream_iterator<int>(std::cout, " ");

  std::generate(std::begin(num1), std::end(num1), gen1);
  std::generate(std::begin(num2), std::end(num2), gen2);

  std::cout << "Original Sequences:\n";
  std::copy(std::begin(num1), std::end(num1), output);
  std::cout << "\n-----------------\n";
  std::copy(std::begin(num2), std::end(num2), output);
  std::cout << "\n=================\n\n";

  std::sort(std::begin(num1), std::end(num1));
  std::sort(std::begin(num2), std::end(num2));

  std::cout << "Sorted Sequences:\n";
  std::copy(std::begin(num1), std::end(num1), output);
  std::cout << "\n-----------------\n";
  std::copy(std::begin(num2), std::end(num2), output);
  std::cout << "\n=================\n\n";

  std::vector<int> merged(num1.size() + num2.size());
  std::merge(std::begin(num1), std::end(num1),
             std::begin(num2), std::end(num2),
             std::begin(merged));
  std::cout << "Merged Sequences:\n";
  std::copy(std::begin(merged), std::end(merged), output);
  std::cout << '\n';

}
