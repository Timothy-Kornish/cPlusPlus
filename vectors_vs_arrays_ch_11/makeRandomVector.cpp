#include <iostream>
#include <vector>
#include <cstdlib>

void print(const std::vector<int>& v) {
  for (int elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
}

void makeRandom(std::vector<int>& v, int size) {
  v.clear();
  int n = rand() % size + 1;
  for (int i = 0; i < n; i++) {
    v.push_back(rand());
  }
}

int main() {
  srand(2);
  std::vector<int> list;

  std::cout << "Vector initially: ";
  print(list);
  makeRandom(list, 20);
  std::cout << "1st random vector: ";
  print(list);
  makeRandom(list, 5);
  std::cout << "2nd random vector: ";
  print(list);
  makeRandom(list, 10);
  std::cout << "3rd random vector: ";
  print(list);
}
