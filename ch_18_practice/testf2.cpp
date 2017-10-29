#include <iostream>
#include "intlist3.h"

void f() {
  Intlist3 my_list;
  my_list.insert(22);
  my_list.insert(5);
  my_list.insert(-44);
  my_list.print();
}

int main() {
  f();
}
