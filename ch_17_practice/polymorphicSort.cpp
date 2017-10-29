#include <iostream>
#include <vector>
#include "comparer.h"

void selection_sort(std::vector<int>& a, Comparer& compare) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    int small = i;

    for (int j = i + 1; j < n; j++) {
      if (compare.compare(a[i], a[small])) {
        small = j;
      }
    }
    if (i != small) {
      compare.swap(a[i], a[small]);
    }
  }
}

void print(const std::vector<int>& a) {
  int n = a.size();
  std::cout << '{';
  if (n > 0) {
    std::cout << a[0];
    for (int i = 1; i < n; i++) {
      std::cout << ", " << a[i];
    }
  }
  std::cout << '}';
}

bool less_than(int a, int b) {
  return a < b;
}

bool greater_than(int a, int b) {
  return a > b;
}

int main() {
  std::vector<int> original;

  original.push_back(23), original.push_back(-3), original.push_back(4), original.push_back(215);
  original.push_back(0), original.push_back(-3), original.push_back(2), original.push_back(23);
  original.push_back(100), original.push_back(88), original.push_back(-1);

  std::vector<int> working = original;
  std::cout << "Before:   ";
  print(working);
  std::cout << '\n';
  Comparer lt(less_than), gt(greater_than);
  selection_sort(working, lt);
  std::cout << "Ascending:  ";
  print(working);
  std::cout << "  (" << lt.comparisons() << " comparisons, "
            << lt.swaps() << " swaps)\n";
  std::cout << "----------------------------\n";

  working = original;
  std::cout << "Before:   ";
  print(working);
  std::cout << '\n';
  selection_sort(working, gt);
  std::cout << "Descending: ";
  print(working);
  std::cout << "  (" << gt.comparisons() << " comparisons, "
            << gt.swaps() << " swaps)\n";
  std::cout << "----------------------------\n";
  std::cout << "Before:   ";
  print(working);
  std::cout << '\n';
  gt.reset();
  selection_sort(working, gt);
  std::cout << "Descending: ";
  print(working);
  std::cout << "  (" << gt.comparisons() << " comparisons, "
            << gt.swaps() << " swaps)\n";
}
