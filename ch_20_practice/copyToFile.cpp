#include <fstream>
#include <vector>
#include <iterator>

int main() {
  std::vector<int> vec { 10, 20, 30, 35, 40, 45, 50, 55 };
  std::ofstream fout("output.txt");

  if (fout.good()) {
    auto strm = std::ostream_iterator<int>(fout, " ");
    std::copy(std::begin(vec), std::end(vec), strm);
    fout << '\n';
  }
}
