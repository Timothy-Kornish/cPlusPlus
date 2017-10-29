#include <iostream>
#include <vector>

class Comparer {
  int compare_count;
  int swap_count;
  bool (*func)(int, int);
public:
  Comparer(bool (*func)(int, int)): compare_count(0), swap_count(0), func(func) {}

  void reset() {
    compare_count = swap_count = 0;
  }

  bool compare(int m, int n) {
    compare_count++;
    return func(m, n);
  }

  void swap(int& m, int& n) {
    swap_count++;
    int temp = m;
    m = n;
    n = temp;
  }

  int comparisons() const {
    return compare_count;
  }

  int swaps() const {
    return swap_count;
  }
};

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
      compare.compare(a[i], a[small]);
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
  std::vector<int> orig; // original, as in original vector
  orig.push_back(23), orig.push_back(-3), orig.push_back(4), orig.push_back(215);
  orig.push_back(0), orig.push_back(-3), orig.push_back(2), orig.push_back(23);
  orig.push_back(100), orig.push_back(88), orig.push_back(4), orig.push_back(-10);

  std::vector<int> working = orig;
  std::cout << "Before:     ";
  print(working);
  std::cout << '\n';
  Comparer lt(less_than), gt(greater_than);
  selection_sort(working, lt);
  std::cout << "Ascending:  ";
  print(working);
  std::cout << "  (" << lt.comparisons() << " comparisons, " << lt.swaps() << " swaps)\n";
  std::cout << "-----------------------------------\n";

  working = orig;
  std::cout << "Before:     ";
  print(working);
  std::cout << '\n';
  selection_sort(working, gt);
  std::cout << "Descending: ";
  print(working);
  std::cout << "  (" << gt.comparisons() << " comparisons, " << gt.swaps() << " swaps)\n";
  std::cout << "-----------------------------------\n";

  std::cout << "Before:     ";
  print(working);
  std::cout << '\n';
  gt.reset();
  selection_sort(working, gt);
  std::cout << "Descending: ";
  print(working);
  std::cout << "  (" << gt.comparisons() << " comparisons, " << gt.swaps() << " swaps)\n";
  std::cout << "-----------------------------------\n";

}
