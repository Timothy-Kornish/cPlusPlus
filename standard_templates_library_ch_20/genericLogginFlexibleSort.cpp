#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

template <typename T>
class Comparer {
  int compare_count;
  int swap_count;
  bool (*comp)(const T&, const T&);

protected:
  virtual bool compare_impl(const T& m, const T& n);
  virtual void swap_impl(T& m, T& n);

public:
  Comparer(bool (*f)(const T&, const T&));
  bool compare(const T& m, const T& n);
  void reset();
  void swap(T& m, T& n);
  int comparisons() const;
  int swaps() const;
};

template <typename T>
bool Comparer<T>::compare_impl(const T& m, const T& n) {
  return comp(m, n);
}

template <typename T>
void Comparer<T>::swap_impl(T& m, T& n) {
  T temp = m;
  m = n;
  n = temp;
}

template <typename T>
Comparer<T>::Comparer(bool (*f)(const T&, const T&)):
                      compare_count(0), swap_count(0), comp(f) {}

template <typename T>
void Comparer<T>::reset() {
  compare_count = swap_count = 0;
}

template <typename T>
bool Comparer<T>::compare(const T& m, const T& n) {
  compare_count++;
  return compare_impl(m, n);
}

template <typename T>
void Comparer<T>::swap(T& m, T& n) {
  swap_count++;
  swap_impl(m, n);
}

template <typename T>
int Comparer<T>::comparisons() const  {
  return compare_count;
}

template <typename T>
int Comparer<T>::swaps() const {
  return swap_count;
}

template <typename T, typename V>
void selection_sort(const T begin, const T end, Comparer<V>& compare) {
  for (auto i = begin; i != end; i++) {
    auto small = i;
    for (auto j = i + 1; j != end; j++) {
      if (compare.compare(*j, *small)) {
        small = j;
      }
    }
    if (i != small) {
      compare.swap(*i, *small);
    }
  }
}

template <typename T>
void print(const T begin, const T end) {
  std::cout << '{';
  if (begin != end) {
    T iter = begin;
    std::cout << *iter;
    iter++;
    while (iter != end) {
      std::cout << ", " << *iter;
      iter++;
    }
  }
  std::cout << '}';
}

template <typename T>
bool less_than(const T& a, const T& b) {
  return a < b;
}

template <typename T>
bool greater_than(const T& a, const T& b) {
  return a > b;
}

template <typename T>
class LogComparer: public Comparer<T> {

  std::ofstream fout;

protected:
  bool compare_impl(const T& m, const T& n) override;
  void swap_impl(T& m, T& n) override;

public:

  LogComparer(bool (*f)(const T&, const T&), const std::string& filename);
  ~LogComparer();
};

template <typename T>
bool LogComparer<T>::compare_impl(const T& m, const T& n) {
  std::cout << "Comparing " << m << " to " << n << '\n';
  return Comparer<T>::compare_impl(m, n);
}

template <typename T>
void LogComparer<T>::swap_impl(T& m, T& n) {
  std::cout << "Swapping " << m << " and " << n << '\n';
  Comparer<T>::swap_impl(m, n);
}

template <typename T>
LogComparer<T>::LogComparer(bool (*f)(const T&, const T&),
                            const std::string& filename): Comparer<T>(f) {
  fout.open(filename);
  if (!fout.good()) {
    std::cout << "Could not open log file " << filename << " for writing\n";
    exit(1);
  }
}

template <typename T>
LogComparer<T>::~LogComparer() {}

int main() {
  std::vector<int> vec = { 23, -3, 10, 4, 215, 0, -3, 2 };
  std::cout << "Before:   ";
  print(std::begin(vec), std::end(vec));
  std::cout << '\n';
  LogComparer<int> lt(less_than<int>, "upsort.log");

  selection_sort(std::begin(vec), std::end(vec), lt);
  std::cout << "Ascending:  ";
  print(std::begin(vec), std::end(vec));
  std::cout << "  (" << lt.comparisons() << " comparisons, "
            << lt.swaps() << " swaps)\n";
  LogComparer<int> gt(greater_than<int>, "downsort.log");
  selection_sort(std::begin(vec), std::end(vec), gt);
  std::cout << "Descending:  ";
  print(std::begin(vec), std::end(vec));
  std::cout << "  (" << gt.comparisons() << " comparisons, "
            << gt.swaps() << " swaps)\n";
  std::cout << "--------------------------------------\n";

  std::vector<std::string> words{"tree", "girl", "boy", "dog",
                         "cat", "girl", "bird"};
  std::cout << "Before:   ";
  print(std::begin(words), std::end(words));
  std::cout << '\n';
  LogComparer<std::string> wlt(less_than<std::string>, "upwords.log");
  selection_sort(std::begin(words), std::end(words), wlt);
  std::cout << "Ascending:  ";
  print(std::begin(words), std::end(words));
  std::cout << "  (" << wlt.comparisons() << " comparisons, "
            << wlt.swaps() << " swaps)\n";
  LogComparer<std::string> wgt(greater_than<std::string>, "downwords.log");
  selection_sort(std::begin(words), std::end(words), wgt);
  std::cout << "Descending:  ";
  print(std::begin(words), std::end(words));
  std::cout << "  (" << wgt.comparisons() << " comparisons, "
            << wgt.swaps() << " swaps)\n";
  std::cout << "--------------------------------------\n";

  int arr[] = { 23, -3, 10, 4, 215, 0, -3, 2 };
  std::cout << "Before:   ";
  print(arr, arr + 8);
  std::cout << '\n';
  LogComparer<int> lt2(less_than<int>, "upsort2.log");
  selection_sort(arr, arr + 8, lt2);
  std::cout << "Ascending:  ";
  print(arr, arr + 8);
  std::cout << "  (" << lt2.comparisons() << " comparisons, "
            << lt.swaps() << " swaps)\n";
  LogComparer<int> gt2(greater_than<int>, "downsort2.log");
  selection_sort(arr, arr + 8, gt2);
  std::cout << "Descending:  ";
  print(arr, arr + 8);
  std::cout << "  (" << gt2.comparisons() << " comparisons, "
            << gt.swaps() << " swaps)\n";

}
