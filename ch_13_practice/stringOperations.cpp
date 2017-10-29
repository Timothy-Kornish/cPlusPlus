#include <iostream>
#include <string>

std::string empty(std::string str) {
  return str.empty() ? "Empty" : "Not Empty";
}

int main() {

  std::string word = "Fred";

  std::cout << "The length of the word \"Fred\" is: "<< word.length() << " characters.\n";

  std::cout << "index 3 is: " << word.operator[](3) << " Or " << word[3] << '\n';

  word.operator=("Sup");
  std::cout << "The word is now: " << word << '\n';
  word.operator+=("-Homie");
  std::cout << "The word is now: " << word << '\n';
  std::cout << "Word should not be empty. Result: " << empty(word) << '\n';
  word.clear();
  std::cout << "Word should now be cleared. Result: " << empty(word) << '\n';

  word = "good";

  std::cout << "word is now: " << word << '\n';

  word += "-bye";
  std::cout << "word is now: " << word << '\n';
  std::cout << "Index 0: " << word[0] << '\n';
  std::cout << "second to last letter in word: " << word[word.length() - 1] << '\n';

  std::cout << "sub-section: " << word.substr(2, 5) << '\n';
  std::string first = "ABC", last = "XYZ";

  std::cout << first + last << '\n';

  std::cout << "Compare " << first << " and ABC: ";
  std::cout << (first == "ABC" ? "equal\n" : "Not equal\n");

  std::cout << "Compare " << first << " and XYZ: ";
  std::cout << (first == "XYZ" ? "equal\n" : "Not equal\n");








}
