#include <iostream>
#include "intlist6.h"

void test() {
  Intlist6 list;
  for (int i = 0; i < 10; i++) {
    list.insert(i);
  }
  list.print();
}

int main() {
  for (int i = 0; i < 10; i++) {
    test();
  }
}
