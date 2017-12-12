#include <iostream>
#include <vector>
#include <iomanip>

using Matrix = std::vector<std::vector<double> >;

void populateMatrix(Matrix& m) {
  std::cout << "Enter the " << m.size() << " rows of the matrix.\n";
  for (unsigned row = 0; row < m.size(); row++) {
    std::cout << "Row #" << row << " (enter " << m[row].size() << " values):";
    for (double& elem : m[row]) {
      std::cin >> elem;
    }
  }
}

void printMatrix(const Matrix m) {
  for (auto row : m) {
    for (double elem : row) {
      std::cout << std::setw(5) << elem;
    }
    std::cout << '\n';
  }
}

int main() {
  int rows, columns;
  std::cout << "How many rows? ";
  std::cin >> rows;
  std::cout << "How many columns? ";
  std::cin >> columns;

  Matrix mat(rows, std::vector<double>(columns));
  populateMatrix(mat);
  printMatrix(mat);
}
