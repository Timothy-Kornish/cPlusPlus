#include "intlist.h"
#include <iostream>
#include <ctype.h>

int main() {
  bool done = false;
  char command;
  int value;
  Intlist1 list;

  while (!done) {
    std::cout << "I)nsert <item>  P)rint  L)ength  E)rase Q)uit >>";
    std::cin >> command;
    command = toupper(command);
    switch(command) {
      case 'I':
        if (std::cin >> value) {
          list.insert(value);
        }
        else {
          done = true;
        }
        break;
      case 'P':
        list.print();
        break;
      case 'L':
        std::cout << "Number of elements: " << list.length() << '\n';
        break;
      case 'E':
        list.clear();
        break;
      case 'Q':
        done = true;
        break;
    }
  }
  list.clear();
}
