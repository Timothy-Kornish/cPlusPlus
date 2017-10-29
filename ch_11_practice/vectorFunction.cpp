#include <iostream>
#include <vector>

void print(std::vector<int> v) {
  for (int elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
}

int sum(std::vector<int> v) {
  int result = 0;
  for (int elem : v) {
    result += elem;
  }
  return result;
}

int main() {
  std::vector<int> list;
  list[0] = 2;
  list[1] = 4;
  list[2] = 6;
  list[3] = 8;
  print(list);
  std::cout << sum(list) << '\n';
  int n = list.size();
  for (int i = 0; i < n; i++) {
    list[i] = 0;
  }
  print(list);
  std::cout << sum(list) << '\n';
}
