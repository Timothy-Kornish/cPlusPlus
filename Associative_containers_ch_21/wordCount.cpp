#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: wordcount <filename>\n";
    std::cout << " where <filename> is the name of a text file.\n";
  }
  else {
    std::string filename = argv[1];
    std::map<std::string, int> counters; // Make a counting dictionary
    std::ifstream fin(filename);
    if (fin.good()) {     // Open the file for reading
      std::string word;
      while (fin >> word) {
        // Capitalize all the letters in the word
        transform(std::begin(word), std::end(word),
        std::begin(word), toupper);
        counters[word]++;   // Increment counter for word
      }
      // Report the counts for each word
      for (auto item : counters)
        std::cout << item.first << ":" << item.second << '\n';
    }
    else {
      std::cout << "Cannot open file for reading\n";
    }
  }
}
