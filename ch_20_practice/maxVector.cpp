#include <iostream>
#include <vector>

using namespace std;

int max(const vector<int>& vec) {
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

bool is_sorted(const vector<int>& vec) {
  for (unsigned i = 0; i < vec.size() - 1; i++) {
    if (vec[i] > vec[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  cout << boolalpha << is_sorted({1, 2, 3, 4, 5}) << '\n';
  cout << boolalpha << is_sorted({5, 4, 3, 2, 1}) << '\n';
  cout << boolalpha << is_sorted({5, 5, 5, 5, 5}) << '\n';
  cout << "-----------------------\n";
  cout << max({1, 2, 3, 4, 5}) << '\n';
  cout << max({5, 4, 3, 2, 1}) << '\n';
  cout << max({3, 4, 5, 2, 1}) << '\n';
  cout << max({5, 2, 3, 4, 5}) << '\n';
  cout << max({5, 4, 5, 2, 5}) << '\n';
  cout << max({5}) << '\n';
  cout << max({5, 5, 5, 5, 5}) << '\n';
}
