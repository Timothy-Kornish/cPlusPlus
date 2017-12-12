#ifndef SETOUTPUT_H_DEFINED_
#define SETOUTPUT_H_DEFINED_

#include <iostream>
#include <set>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
  os << '{';
  auto iter = std::begin(s);
  auto done = std::end(s);
  if (iter != done) {
    os << *iter++;
    while (iter != done) {
      os << ", " << *iter++;
    }
  }
  os << '}';
  return os;
}

#endif
