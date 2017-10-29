#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class FileNotFoundException : public std::exception {
  std::string message;
public:
  FileNotFoundException(const std::string& fname):
              message("File \"" + fname + "\" not found ") {}
  const char what() const () {
    return message.c_str();
  }
};

std::vector<int> load_vector(const std::string& filename) {
  std::ifstream fin(filename);
  if(fin.good()) {
    std::vector<int> result;
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
      int value;
      fin >> value;
      result.push_back(value);
    }
    return result;
  }
  else {
    throw FileNotFoundException(filename);
  }
}

int main (){
  try {
    std::vector<int> numbers = load_vector("value.data");
    for (int value : numbers) {
      std::cout << value << ' ';
    }
    std::cout << '\n';
  }
  catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
}
