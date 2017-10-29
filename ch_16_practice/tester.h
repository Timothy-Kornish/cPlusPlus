#ifndef TESTER_H_
#define TESTER_H_

#include <vector>
#include <string>

class Tester {
  int error_count;
  int total_count;

  bool equals(double d1, double d2, double tolerance) const;

  void print_vector(const std::vector<int>& a);
public:
  Tester();

  void check_equals(const std::string& msg, int expected, int actual);

  void check_equals(const std::string& msg, double expected,
                             double actual, double tolerance);

  void check_equals(const std::string& msg,
                    const std::vector<int>& expected,
                    const std::vector<int>& actual);

  void report_results() const;

};

#endif
