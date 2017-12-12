#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  vec.push_back(10), vec.push_back(20), vec.push_back(30), vec.push_back(40);
  vec.push_back(50);

  std::vector<int>::iterator iter = std::begin(vec);

  std::cout << *iter << '\n';
  iter++;
  std::cout << *iter << '\n'; 
}
