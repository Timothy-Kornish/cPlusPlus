#include <vector>
#include <iostream>

using Iter = std::vector<int>::iterator;

int count_value(Iter iter_begin, Iter iter_end, int seek) {
  int count = 0;
  for (Iter cursor = iter_begin; cursor != iter_end; cursor++) {
    if (*cursor == seek) {
      count++;
    }
  }
  return count;
}

int main() {
  std::vector<int> a;

  a.push_back(34), a.push_back(5), a.push_back(12), a.push_back(5);
  a.push_back(8), a.push_back(5), a.push_back(11), a.push_back(2);

  std::cout << count_value(std::begin(a), std::end(a), 5) << '\n';
  std::cout << count_value(std::begin(a), std::end(a), 12) << '\n';
  std::cout << count_value(std::begin(a), std::end(a), 13) << '\n';

}
