#include <iostream>
#include <cmath>
#include "tester.h"

Tester::Tester(): error_count(0), total_count(0) {
  std::cout << "+---------------------------------------\n";
  std::cout << "|  Testing \n";
  std::cout << "+---------------------------------------\n";
}

bool Tester::equals(double d1, double d2, double tolerance) const {
  return d1 == d2 || std::abs(d1 - d2) < tolerance;
}

void Tester::print_vector(const std::vector<int>& a) {
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

void Tester::check_equals(const std::string& msg, int expected, int actual) {
  std::cout << "[" << msg << "] ";
  total_count++;
  if (expected == actual) {
    std::cout << "OK\n";
  }
  else {
    error_count++;
    std::cout << "*** Failed! Expected: " << expected
              << ", Actual: " << actual << '\n';
  }
}

void Tester::check_equals(const std::string& msg, double expected, double actual, double tolerance) {
  std::cout << "[" << msg << "] ";
  total_count++;
  if (equals(expected, actual, tolerance)) {
    std::cout << "OK\n";
  }
  else {
    error_count++;
    std::cout << "*** Failed! Expected: " << expected
              << ", Actual: " << actual << '\n';
  }
}

void Tester::check_equals(const std::string& msg,
                           const std::vector<int>& expected,
                           const std::vector<int>& actual) {
  std::cout << "[" << msg << "] ";
  total_count++;
  if (expected == actual) {
    std::cout << "OK\n";
  }
  else {
    error_count++;
    std::cout << "*** Failed! Expected: ";
    print_vector(expected);
    std::cout << ", Actual: ";
    print_vector(actual);
    std::cout << '\n';
  }
}

void Tester::report_results() const {
  std::cout << "+--------------------------------------\n";
  std::cout << "| " << total_count << " tests run, "
            << total_count - error_count << " passed, "
            << error_count << " failed\n";
  std::cout << "+--------------------------------------\n";
}
