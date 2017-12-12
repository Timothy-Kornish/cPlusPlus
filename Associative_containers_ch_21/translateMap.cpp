#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using Dict = std::map<std::string, std::string>; // Dict for Dictionary

Dict word_map;

void load_words(std::string filename, Dict& words) {
  std::ifstream in(filename);
  if (in.good()) {
    std::string english_word, spanish_word;
    while (in >> spanish_word >> english_word) {
      words[spanish_word] = english_word;
    }
  }
  else {
    std::cout << "Unable to load in the file\n";
  }
}

int main() {
  load_words("engSpanWords.txt", word_map);

  std::string word = "";
  while (word != "quit") {
    std::cout << "Enter Spanish word: ";
    std::cin >> word;
    std::cout << word << ": " << word_map[word] << '\n';
  }
}
