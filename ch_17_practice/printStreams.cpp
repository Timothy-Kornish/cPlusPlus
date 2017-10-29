#include <fstream>
#include <iostream>

void print(std::ostream& os, int n) {
  os.width(10);
  os.fill('*');
  os << n << '\n';
}

int main() {
  print(std::cout, 35);

  std::ofstream fout("temp.data");
  if (fout.good()) {
    print(fout, 36);
  }
}
