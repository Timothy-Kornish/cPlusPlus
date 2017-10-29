#include <iostream>
#include <list>
#include <ctype.h>

int main() {
  bool done = false;
  char command;
  int value;
  std::list<int> myList;

  while (!done) {
    std::cout << "I)nsert <item>  P)rint  L)ength  E)rase Q)uit >>";
    std::cin >> command;
    command = toupper(command);
    switch(command) {
      case 'I':
        if (std::cin >> value) {
          myList.push_back(value);
        }
        else {
          done = true;
        }
        break;
      case 'P':
        for (const auto& elem : myList) {
          std::cout << elem << ", ";
        }
        std::cout << '\n';
        break;
      case 'L':
        std::cout << "Number of elements: " << myList.size() << '\n';
        break;
      case 'E':
        myList.clear();
        break;
      case 'Q':
        done = true;
        break;
    }
  }
}
