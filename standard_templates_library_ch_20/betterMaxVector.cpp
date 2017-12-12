#include <iostream>
#include <vector>
#include <algorithm>

int max(const std::vector<int>& vec) {
  auto p = std::begin(vec);

  int m = *p++;
  while (p != std::end(vec)) {
    if (*p > m) {
      m = *p;
    }
    p++;
  }

  int count = 0;
  for (auto elem: vec) {
    if (elem == m) {
      count++;
    }
  }
  return count;
}

bool is_sorted(const std::vector<int>& vec) {
  for (unsigned i = 0; i < vec.size() - 1; i++) {
    if (vec[i] > vec[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::cout << std::boolalpha << is_sorted({1, 2, 3, 4, 5}) << '\n';
  std::cout << std::boolalpha << is_sorted({5, 4, 3, 2, 1}) << '\n';
  std::cout << std::boolalpha << is_sorted({5, 5, 5, 5, 5}) << '\n';
  std::cout << "-----------------------\n";
  std::cout << max({1, 2, 3, 4, 5}) << '\n';
  std::cout << max({5, 4, 3, 2, 1}) << '\n';
  std::cout << max({3, 4, 5, 2, 1}) << '\n';
  std::cout << max({5, 2, 3, 4, 5}) << '\n';
  std::cout << max({5, 4, 5, 2, 5}) << '\n';
  std::cout << max({5}) << '\n';
  std::cout << max({5, 5, 5, 5, 5}) << '\n';
}
