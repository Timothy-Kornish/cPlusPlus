#include <iostream>
#include <vector>
#include "logcomparer.h"

void selection_sort(std::vector<int>& a, Comparer& compare) {
  int n = a.size();

  for (int i = 0; i < n - 1; i++) {
    int small = i;
    for (int j = i + 1; j < n; j++) {
      if (compare.compare(a[j], a[small])) {
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
  std::cout << "}\n";
}

bool less_than(int a, int b) {
  return a < b;
}

int main() {

  // needs a lot of functions created to work
  int a[] = { 23, -3, 4, 215, 0, -3, 2 };
  int len = (sizeof a)/(sizeof a[0]);
  std::vector<int> vec(a, a + len);
  std::cout << "Before:   ";
  print(vec);
  std::cout << '\n';
  LogComparer lt(less_than, "sort.log");
  selection_sort(vec, lt);
  std::cout << "Ascending: ";
  print(vec);
  std::cout << "  (" << lt.comparisons() << " comparisons, "
            << lt.swaps() << " swaps)\n";
}
