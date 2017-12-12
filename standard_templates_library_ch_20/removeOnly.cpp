#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

bool is_even(int n) {
  return n % 2 == 0;
}

int main() {
  std::vector<int> nums(20);
  auto output = std::ostream_iterator<int>(std::cout, " ");

  std::iota(std::begin(nums), std::end(nums), 0);
  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << '\n';

  std::remove(std::begin(nums), std::end(nums), 5);
  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << '\n';

  std::remove_if(std::begin(nums), std::end(nums), is_even);
  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << '\n';

}
