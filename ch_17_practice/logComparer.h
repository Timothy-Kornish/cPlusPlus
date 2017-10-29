#ifndef LOG_COMPARER_H_
#define LOG_COMPARER_H_

#include <fstream>
#include <string>
#include "comparer.h"

class LogComparer: public Comparer {
  std::ofstream fout;
protected:
  bool compare_impl(int m, int n) override;
  void swap_impl(int& m, int& n) override;
public:
  LogComparer(bool (*f)(int, int), const std::string& filename);

  ~LogComparer();
};

#endif
