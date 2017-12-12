#include <iostream>
#include <set>

struct MyClass {
  int data;
  MyClass(int d): data(d) {}
};

bool operator<(const MyClass& a, const MyClass& b) {
  return a.data < b.data;
}

std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
  os << obj.data;
  return os;
}

int main() {
  std::set<int> S {10, 3, 7, 2, 7, 11, 3};
  for (auto elem : S) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  std::set<int> T {5, 4, 5, 2, 4, 9};
  for (auto elem : T) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  std::set<MyClass> U {MyClass(10), MyClass(3), MyClass(7), MyClass(2)};
  for (auto elem : U) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}
