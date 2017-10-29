#include "logComparer.h"
#include <cstdlib>
#include <iostream>
#include <string>

bool LogComparer::compare_impl(int m, int n) {
  fout << "Comparing " << m << " to " << n << '\n';
  return Comparer::compare_impl(m, n);
}

void LogComparer::swap_impl(int& m, int& n) {
  fout << "Swapping " << m << " and " << n << '\n';
  int temp = m;
  m = n;
  n = temp;
}

LogComparer::LogComparer(bool (*f)(int, int), const std::string& filename):
                         Comparer(f) {
  fout.open(filename);
  if(!fout.good()) {
    std::cout << "Could not open log file << " << filename << " for writing\n";
    exit(1);
  }
}
