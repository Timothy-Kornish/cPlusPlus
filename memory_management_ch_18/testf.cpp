#include <iostream>
#include "list.h"

void f() {
  Intlist2 my_list;
  my_list.insert(22);
  my_list.insert(5);
  my_list.insert(-44);
  my_list.print();
}

int main() {
  f();
}
