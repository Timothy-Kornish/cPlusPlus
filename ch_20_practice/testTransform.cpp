#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  const int SIZE = 20;

  std::vector<int> seq(SIZE);
  std::iota(std::begin(seq), std::end(seq), 0);
  std::cout << "Original: ";
  std::for_each(std::begin(seq), std::end(seq), [](int x) { std::cout << x << ' ';});
  std::cout << "\n--------------------------------------------\n";

  std::vector<int> seq2(SIZE);
  std::copy(std::begin(seq), std::end(seq), std::begin(seq2));
  std::cout << "Copy: ";
  std::for_each(std::begin(seq2), std::end(seq2), [](int x) { std::cout << x << ' '; });
  std::cout << "\n--------------------------------------------\n";

  std::vector<int> seq3(SIZE);
  std::transform(std::begin(seq), std::end(seq), std::begin(seq3), [](int n) { return 2 * n; });
  std::cout << "Transform: ";
  std::for_each(std::begin(seq3), std::end(seq3), [](int x) { std::cout << x << ' '; });
  std::cout << "\n--------------------------------------------\n";
}
