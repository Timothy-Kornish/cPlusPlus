#include <iostream>
#include "linkedlist.h"

int main() {
  LinkedList<int> intlist1, intlist2, intlist3;
  for (int i = 10; i < 50; i+=10){
    intlist1.insert(i);
  }
  for (int i = 100; i < 500; i+=100){
    intlist1.insert(i);
  }
  for (int i = 5; i < 25; i+=5){
    intlist1.insert(i);
  }

  LinkedList<LinkedList<int> > listoflists;
  listoflists.insert(intlist1);
  listoflists.insert(intlist2);
  listoflists.insert(intlist3);
  std::cout << "--------------------\n";
  std::cout << listoflists << '\n';
  std::cout << "--------------------\n";
}
