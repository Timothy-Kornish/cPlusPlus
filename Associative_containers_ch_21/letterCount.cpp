#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: lettercount <filename>\n";
    std::cout << " where <filename> is the name of a text file.\n";
  }
  else {
    std::string filename = argv[1];
    std::vector<int> counters(26,0);
    std::ifstream fin(filename);
    if (fin.good()) {
      char ch;
      while (fin >> ch) {
        ch = static_cast<char>(toupper(ch));
        if(isalpha(ch)) {
          counters[ch - 'A']++;
        }
      }

      ch = 'A';
      for (auto count : counters) {
        std::cout << ch++ << ": " << count << '\n';
      }
    }
    else {
      std::cout << "Cannot open file for reading\n";
    }
  }
}
