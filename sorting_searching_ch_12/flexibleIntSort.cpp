#include <iostream>
#include <vector>

bool less_than(int a, int b) {
  return a < b;
}

bool greater_than(int a, int b) {
  return a > b;
}

void selection_sort(std::vector<int>& a, bool (*compare)(int, int)) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    int small = i;
    for (int j = i + 1; j < n; j++) {
      if (compare(a[j], a[small])) {
        small = j;
      }
    }
    if (i != small) {
      std::swap(a[i], a[small]);
    }
  }
}

void print(const std::vector<int>& a) {
  int n = a.size();
  std::cout << '{';
  if(n > 0) {
    std::cout << a[0];
    for (int i = 1; i < n; i++) {
      std::cout << ", " << a[i];
    }
  }
  std::cout << '}';
}

int main() {
  std::vector<int> list;
  list.push_back(23);
  list.push_back(2);
  list.push_back(3);
  list.push_back(13);
  list.push_back(25);
  list.push_back(-6);
  list.push_back(239);

  std::cout << "Original:  ";
  print(list);
  std::cout << '\n';
  selection_sort(list, less_than);
  std::cout << "Ascending:  ";
  print(list);
  std::cout << '\n';
  selection_sort(list, greater_than);
  std::cout << "Descending:  ";
  print(list);
  std::cout << '\n';
}
