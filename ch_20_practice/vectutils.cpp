#include "vectutils.h"

namespace vecutils {

int max(const std::vector<int>& vec) {
  auto p = std::begin(vec);

  int m = *p++;
  while (p != std::end(vec)) {
    if (*p > m) {
      m = *p;
    }
    p++;
  }

  int count = 0;
  for (auto elem: vec) {
    if (elem == m) {
      count++;
    }
  }
  return count;
}

bool is_sorted(const std::vector<int>& vec) {
  for (unsigned i = 0; i < vec.size() - 1; i++) {
    if (vec[i] > vec[i + 1]) {
      return false;
    }
  }
  return true;
}

}
