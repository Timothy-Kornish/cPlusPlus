#include <iostream>
#include <vector>
#include <algorithm>


void print(const std::vector<int>& a) {
  int n = a.size();
  std::cout << "{";
  if (n > 0) {
    std::cout << a[0];
    for (int i = 1; i < n; i++) {
      std::cout << ", " << a[i];
    }
  }
  std::cout << "}";
}

int main() {
  std::vector<int> nums;
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  
  std::cout << "---------------\n";
  do {
    print(nums);
    std::cout << '\n';
  } while (next_permutation(begin(nums), std::end(nums)));
}
