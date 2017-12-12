#include <vector>
#include <iostream>

int main(){
  std::vector<int> vec;
  vec.push_back(10), vec.push_back(20), vec.push_back(30), vec.push_back(40);
  vec.push_back(50);

  for (auto iter = std::begin(vec); iter != std::end(vec); iter++) {
    std::cout << *iter << ' ';
  }
  std::cout << '\n';
}
