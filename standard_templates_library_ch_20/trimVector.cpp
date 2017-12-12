#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> seq{ 2, 3, 4, 5, 6 };
  std::for_each(std::begin(seq), std::end(seq), [](int x) { std::cout << x << ' '; });
  std::cout << '\n';

  if (seq.size() >= 2) {
    std::vector<int> seq2(seq.size() - 2);
    std::copy(std::begin(seq) + 1, std::end(seq) - 1, std::begin(seq2));

    std::for_each(std::begin(seq2), std::end(seq2), [](int x) { std::cout << x << ' '; });
    std::cout << '\n';
  }
}
