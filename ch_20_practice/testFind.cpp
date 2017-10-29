#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  std::vector<int> seq(1000,0);

  std::iota(std::begin(seq), std::end(seq), 0);

  auto iter = std::find(std::begin(seq), std::end(seq), 678);

  if (iter != std::end(seq)) {
    std::cout << *iter << " is present" << '\n';
  }
  else {
    std::cout << "678 is Not present" << '\n';
  }

  iter = std::find(std::begin(seq), std::end(seq), -200);

  if (iter != std::end(seq)) {
    std::cout << *iter << " is present" << '\n';
  }
  else {
    std::cout << "-200 is Not present" << '\n';
  }
}
