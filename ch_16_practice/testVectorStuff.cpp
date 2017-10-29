#include <iostream>
#include <vector>
#include "tester.h"

void sort(std::vector<int>& vec) {

}

int sum(const std::vector<int>& vec) {
  int total = 0;
  for (size_t i = 1; i < vec.size(); i++) {
    total += vec[i];
  }
  return total;
}

int main() {
  Tester t;

  std::vector<int> vec, vec1, vec2, vec3;
  vec.push_back(4), vec.push_back(2), vec.push_back(3);
  vec1.push_back(2), vec1.push_back(3), vec1.push_back(4);
  vec2.push_back(0), vec2.push_back(3), vec2.push_back(4);
  vec3.push_back(-3), vec3.push_back(0), vec3.push_back(5);

  sort(vec);
  t.check_equals("Sort test #1", vec1, vec);
  vec = vec1;
  sort(vec);

  t.check_equals("Sort test #2", vec1, vec);
  t.check_equals("Sum test #1", sum(vec2), 7);
  t.check_equals("Sum test #2", sum(vec3), 2);

}
