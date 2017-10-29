#include <iostream>
#include <string>

int main() {
  std::string line;
  std::cout << "Please enter a line of text: ";
  //std::cin >> line; the text entered is truncated at the first space in the input
  getline(std::cin, line);
  std::cout << "You entered: \"" << line << "\"\n";
}
