#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

void print_vector(const std::vector<int>& vec) {
  std::cout << '{';
  int len = vec.size();
  if (len > 0) {
    for (int i = 0; i < len - 1; i++) {
      std::cout << vec[i] << ", ";
    }
    std::cout << vec[len - 1];
  }
  std::cout << "}\n";
}

void save_vector(const std::string& filename, const std::vector<int>& vec) {
  std::ofstream out(filename);
  if (out.good()) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
      out << vec[i] << " ";
    }
    out << '\n';
  }
  else {
    std::cout << "Unable to save the file.\n";
  }
}

void load_vector(const std::string& filename, std::vector<int>& vec) {
  std::ifstream in(filename);
  if (in.good()) {
    vec.clear();
    int value;
    while (in >> value) {
      vec.push_back(value);
    }
  }
  else {
    std::cout << "Unable to load in the file.\n";
  }
}

int main() {
  std::vector<int> list;
  bool done = false;
  char command;
  while (!done) {
    std::cout << "I)nsert <item> P)rint "
              << "S)ave <filename> L)oad <filename> "
              << "E)rase Q)uit: ";
    std::cin >> command;
    int value;
    std::string filename;
    command = toupper(command);
    switch(command) {
      case 'I':
        std::cin >> value;
        list.push_back(value);
        break;
      case 'P':
        print_vector(list);
        break;
      case 'S':
        std::cin >> filename;
        save_vector(filename, list);
        break;
      case 'L':
        std::cin >> filename;
        load_vector(filename, list);
        break;
      case 'E':
        list.clear();
        break;
      case 'Q':
        done = true;
        break;
      default:
        std::cout << "What up stupid?";
        break;
    }

  }
}
