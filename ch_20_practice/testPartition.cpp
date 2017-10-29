#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>

#include "uniformrandom.h"

int main() {
  std::vector<int> nums(25);
  UniformRandomGenerator gen(0, 100);

  auto int_output = std::ostream_iterator<int>(std::cout, " ");

  std::generate(std::begin(nums), std::end(nums), gen); // generate values in list

  std::cout << "Original Sequence: \n";
  std::copy(std::begin(nums), std::end(nums), int_output); // prints the list from int_output
  std::cout << "\n------------------------------------\n";
  std::cout << "Partitioned Sequence: (evens first then everything else after)\n";
  std::partition(std::begin(nums), std::end(nums), [](int n) {return n % 2 == 0; }); // takes odd numbers and pushes them to the back of the list
  std::copy(std::begin(nums), std::end(nums), int_output);
  std::cout << "\n====================================\n\n";

  auto string_output = std::ostream_iterator<std::string>(std::cout, " ");
  std::vector<std::string> words {"fred", "ella", "adam", "jo",
                                  "pat", "mel", "anna", "ed",
                                  "oscar", "will", "tom", "ingrid" };

  std::cout << "Original Sequence: \n";
  std::copy(std::begin(words), std::end(words), string_output);
  std::cout << "\n------------------------------------\n";
  std::cout << "Partitioned Sequence: (words longer thatn 3 letters first, rest at the end)\n";
  std::partition(std::begin(words), std::end(words),
                 [](const std::string& w) { return w.length() > 3;}); // takes a word less thn 3 characters and pushs it to the back of the list.
  std::copy(std::begin(words), std::end(words), string_output);
  std::cout << '\n';



}
