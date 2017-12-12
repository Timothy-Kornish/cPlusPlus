#include <iostream>
#include <fstream>
#include <vector>

int main() {
  try {
    std::ifstream fin("data.dat");
    if (fin.good()) {
      int n;
      fin >> n;
      std::vector<int> data(n);
      for (int i = 0; i <= n; i++) {
        int value;
        fin >> value;
        data.at(i) = value;
      }
      for (auto value : data) {
        std::cout << value << ' ';
      }
      std::cout << '\n';
    }
    else {
      std::cout << "File does not exits\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
}
