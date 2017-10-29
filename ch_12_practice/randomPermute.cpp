#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

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

int random(int begin, int end) {
  if (begin >= end) {
    return 0;
  }
  else {
    int range = end - begin;
    return begin + rand() % range;
  }
}

void permute(std::vector<int>& a) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    std::swap(a[i], a[random(i,n)]);
  }
}

int main() {
  srand(static_cast<int>(time(0)));

  std::vector<int> vec;
  vec.push_back(1), vec.push_back(2);
  vec.push_back(3), vec.push_back(4);
  vec.push_back(5), vec.push_back(6);
  vec.push_back(7), vec.push_back(8);

  print(vec);
  std::cout << '\n';

  permute(vec);

  print(vec);
  std::cout << '\n';
}
