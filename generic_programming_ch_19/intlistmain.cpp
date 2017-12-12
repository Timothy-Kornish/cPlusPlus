#include <iostream>
#include <ctype.h> // for toupper() funciton
#include "linkedlist.h"

int main() {
  bool done = false;
  char command;
  int value;
  LinkedList<int> list;

  while (!done) {
    std::cout << "I)nsert <item>  D)elete <item> P)rint  L)ength  E)rase Q)uit >>";
    std::cin >> command;
    command = toupper(command);
    switch(command) {
      case 'I':
        if(std::cin >> value) {
          list.insert(value);
        }
        else {
          done = true;
        }
        break;
      case 'D':
        if (std::cin >> value){
          if(list.remove(value)){
            std::cout << value << " removed\n";
          }
          else {
            std::cout << value << " not found\n";
          }
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
}
