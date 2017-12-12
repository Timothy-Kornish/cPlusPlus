#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstdlib>

using Vector = std::vector<int>;

Vector make_random_vector(int size, int max) {
  Vector result(size);
  for (int i = 0; i < size; i++) {
    result[i] = rand() % max;
  }
  return result;
}

void print_with_endl(const Vector& vs, std::ostream& out) {
  for (auto elem : vs) {
    out << elem << std::endl;
  }
}

void print_with_n(const Vector& vs, std::ostream& out) {
  for (auto elem : vs) {
    out << elem << '\n';
  }
}

int main() {
  auto seq = make_random_vector(100000, 100); // (100,000, 100)

  clock_t start_time = clock();
  print_with_endl(seq, std::cout);
  unsigned elapsed1 = clock() - start_time;

  start_time = clock();
  print_with_n(seq, std::cout);
  unsigned elapsed2 = clock() - start_time;

  std::ofstream fout("temp.out");
  start_time = clock();
  print_with_endl(seq, fout);
  fout.close();
  unsigned elapsed3 = clock() - start_time;

  fout.open("temp.out");
  start_time = clock();
  print_with_n(seq, fout);
  fout.close();
  unsigned elapsed4 = clock() - start_time;

  std::cout << "With std::endl (console): " << elapsed1 << '\n';
  std::cout << "With '\\n' (console):     " << elapsed2 << '\n';
  std::cout << "With std::endl (file):    " << elapsed3 << '\n';
  std::cout << "With '\\n' (file):        " << elapsed4 << '\n';

}
