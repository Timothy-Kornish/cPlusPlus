#include <iostream>
#include <vector>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void selectionSortAscend(std::vector<int>& a) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    int small = i;

    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[small]){
        small = j;
      }
    }
    if (i != small) {
      swap(a[i], a[small]);
    }
  }
}

void selectionSortDescend(std::vector<int>& a) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    int small = i;

    for (int j = i + 1; j < n; j++) {
      if (a[j] > a[small]){
        small = j;
      }
    }
    if (i != small) {
      swap(a[i], a[small]);
    }
  }
}

void print(const std::vector<int>& a) {
  int n = a.size();
  std::cout << '{';
  if (n > 0) {
    std::cout << a[0];
    for (int i = 1; i < n; i++) {
      std::cout << ',' << a[i];
    }
  }
  std::cout << '}';
}

int main() {
  std::vector<int>list;
  list.push_back(23);
  list.push_back(-3);
  list.push_back(4);
  list.push_back(215);
  list.push_back(0);
  std::cout << "Before List is Sorted: ";
  print(list);
  std::cout << '\n';
  selectionSortAscend(list);
  std::cout << "After (Ascending): ";
  print(list);
  std::cout << '\n';
  selectionSortDescend(list);
  std::cout << "After (Descending): ";
  print(list);
  std::cout << '\n';
}
