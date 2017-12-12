#include <iostream>
#include <vector>
#include <string>
#include "genericComparer.h"

template <typename T>
void selection_sort(std::vector<T>& a, Comparer<T>& compare) {
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

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& a) {
  int n = a.size();
  os << '{';
  if (n > 0) {
    os << a[0];
    for (int i = 1; i < n; i++) {
      std::cout <<  ", " << a[i];
    }
  }
  os << '}';
  return os;
}

template <typename T>
bool less_than(const T& a, const T& b) {
  return a < b;
}

template <typename T>
bool greater_than(const T& a, const T& b) {
  return a > b;
}

int main() {
  std::vector<int> original;
  std::vector<std::string> str_original;

  original.push_back(23), original.push_back(-3), original.push_back(4), original.push_back(215);
  original.push_back(0), original.push_back(234), original.push_back(3), original.push_back(2);
  original.push_back(13), original.push_back(36), original.push_back(88);

  str_original.push_back("tree"), str_original.push_back("girl"), str_original.push_back("boy");
  str_original.push_back("apple"), str_original.push_back("dog"), str_original.push_back("cat");
  str_original.push_back("bird");

  std::vector<int> working = original;
  std::cout << "Before:   ";
  std::cout << working << '\n';
  Comparer<int> lt(less_than<int>), gt(greater_than<int>);
  selection_sort(working, lt);
  std::cout << "Ascending:  ";
  std::cout << working << '\n';
  std::cout << "  (" << lt.comparisons() << " comparisons, "
            << lt.swaps() << " swaps)\n";
  std::cout << "----------------------------\n";

  working = original;
  std::cout << "Before:   ";
  std::cout << working << '\n';
  selection_sort(working, gt);
  std::cout << "Descending: ";
  std::cout << working << '\n';
  std::cout << "  (" << gt.comparisons() << " comparisons, "
            << gt.swaps() << " swaps)\n";
  std::cout << "----------------------------\n";

  std::vector<std::string> str_working = str_original;
  std::cout << "Before:   ";
  std::cout << str_working << '\n';
  Comparer<std::string> str_lt(less_than<std::string>),
                        str_gt(greater_than<std::string>);
  selection_sort(str_working, str_lt);
  std::cout << "Ascending:  ";
  std::cout << str_working << '\n';
  std::cout << "  (" << str_lt.comparisons() << " comparisons, "
            << str_lt.swaps() << " swaps)\n";
  std::cout << "----------------------------\n";

  str_working = str_original;
  std::cout << "Before:   ";
  std::cout << str_working << '\n';
  selection_sort(str_working, str_gt);
  std::cout << "Descending: ";
  std::cout << str_working << '\n';
  std::cout << "  (" << str_gt.comparisons() << " comparisons, "
            << str_gt.swaps() << " swaps)\n";
  std::cout << "----------------------------\n";
}
