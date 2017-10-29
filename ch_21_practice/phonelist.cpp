#include <iostream>
#include <string>
#include <map>
#include <algorithm>
//#include <ctype.h>

int main() {
  std::map<std::string, int> contacts;
  bool running = true;

  while (running) {
    std::string name;
    int number;
    char command;
    std::cout << "A)dd L)ook up Q)uit: ";
    std::cin >> command;
    command = toupper(command);

    switch(command) {
      case 'A':
        std::cin >> name;
        std::transform(std::begin(name), std::end(name),
                       std::begin(name), toupper);
        std::cin >> number;
        contacts[name] = number;
        break;
      case 'L':
        std::cin >> name;
        std::transform(std::begin(name), std::end(name),
                       std::begin(name), ::toupper);
        std::cout << name << " " << contacts[name] << '\n';
        break;
      case 'Q':
        running = false;
        break;
      case 'D':
        for (auto& elem : contacts) {
          std::cout << elem.first << " " << elem.second << '\n';
        }
        break;
      default:
        std::cout << command << " is not a valid command" << '\n';
    }
  }
}
