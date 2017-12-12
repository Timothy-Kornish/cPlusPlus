#include <iostream>
#include <vector>
#include <iterator>

int main() {
  std::vector<int> vec { 10, 20, 30, 35, 40, 45, 50, 55 };
  auto strm = std::ostream_iterator<int>(std::cout, " ");
  std::copy(std::begin(vec), std::end(vec), strm);
  std::cout << '\n';
}
