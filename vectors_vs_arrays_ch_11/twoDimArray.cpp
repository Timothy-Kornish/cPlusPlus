#include <iostream>
#include <iomanip>

const int ROWS = 3, COLUMNS = 5;

using Matrix = double[ROWS][COLUMNS];

void populateMatrix(Matrix m) {
  std::cout << "Enter the " << ROWS << " rows of the matrix.\n";
  for (int row = 0; row < ROWS; row++) {
    std::cout << "Row # " << row << " (enter " << COLUMNS << " values): ";
    for (int col = 0; col < COLUMNS; col++) {
      std::cin >> m[row][col];
    }
  }
}

void printMatrix(const Matrix m) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLUMNS; col++) {
      std::cout << std::setw(5) << m[row][col];
    }
    std::cout << '\n';
  }
}

int main() {
  Matrix mat;

  populateMatrix(mat);

  printMatrix(mat);
}
