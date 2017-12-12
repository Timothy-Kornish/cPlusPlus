#include <iostream>
#include "intlist5.h"

Intlist5 make_list(int n) {
  Intlist5 result;
  for (int i = 0; i < n; i++) {
    result.insert(i);
  }
  return result;
}

int main() {
  auto my_list = make_list(5);
  my_list.print();
}
