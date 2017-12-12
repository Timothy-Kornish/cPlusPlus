#include <iostream>
#include <vector>
#include <iterator>

int main() {
  std::vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  auto output = std::ostream_iterator<int>(std::cout, " ");

  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << '\n';

  nums.erase(std::begin(nums) + 3, std::end(nums) - 2);
  std::copy(std::begin(nums), std::end(nums), output);
  std::cout << '\n';
}
