#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

int binary_search(const std::vector<int>& a, int seek) {
  int first = 0,
  last = a.size() - 1,
  mid;

  while (first <= last) {
    mid = first + (last - first + 1) / 2;

    if (a[mid] == seek) {
      return mid;
    }
    else if (a[mid] > seek) {
      last = mid - 1;
    }
    else {
      first = mid + 1;
    }
  }
  return -1;
}

int linear_search(const std::vector<int>& a, int seek) {
  int n = a.size();
  for (int i = 0; i < n && a[i] <= seek; i++) {
    if (a[i] == seek) {
      return i;
    }
  }
  return -1;
}

double time_execution(int (*search)(const std::vector<int>&, int),
                      std::vector<int>& v, int trials) {
  int n = v.size();
  double elapsed = 0.0;

  for (int iters = 0; iters < trials; iters++) {
    clock_t start_time = clock();
    for (int i = 0; i < n; i++) {
      search(v, i);
    }
    clock_t end_time = clock();
    elapsed +=  static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
  }
  return elapsed / trials;
}

int main() {
  std::cout << "---------------------------------------\n";
  std::cout << "  Vector        Linear         Binary  \n";
  std::cout << "   Size         Search         Search  \n";
  std::cout << "---------------------------------------\n";

  for (int size = 0; size <=100000; size += 5000) {
    std::vector<int> list(size);

    for (int i = 0; i < size; i++) {
      list[i] = 1;
    }
    std::cout << std::setw(7) << size;
    std::cout << std::fixed << std::setprecision(3) << std::setw(12)
              << time_execution(linear_search, list, 5) << " sec";
    std::cout << std::fixed << std::setprecision(3) << std::setw(12)
              << time_execution(binary_search, list, 25) << " sec\n";
  }
}
