#include "intlist3.h"
#include <iostream>

void f() {
  Intlist3 seq1, seq2;

  seq1.insert(10);  // Build the list [10]-->[-2]-->[8]
  seq1.insert(-2);
  seq1.insert(8);
  seq1.print();

  seq2.insert(5);
  seq2.insert(4);
  seq2.print();

  std::cout << "-----------------\n";
  seq1 = seq2;

  seq1.print();
}

int main() {
  f();
  std::cout << "All done\n";
}
