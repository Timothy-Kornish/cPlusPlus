#include <iostream>
#include <iomanip>

void colNumbers(int n) {
  std::cout << "     ";
  for (int column = 1; column <= n; column++) {
    std::cout << std::setw(4) << column;
  }
  std::cout << '\n';
}

void colLine(int n) {
  std::cout << "    +";
  for (int column = 1; column <= n; column++) {
    std::cout << "----";
  }
  std::cout << '\n';
}

void colHeader(int n){
  colNumbers(n);
  colLine(n);
}

void rowHeader(int n) {
  std::cout << std::setw(4) << n << " |";
}

void printRow(int row, int columns) {
  rowHeader(row);
  for (int col = 1; col <= columns; columns++) {
    std::cout << std::setw(4) << row*col;
  }
  std::cout << '\n';
}

void printContents(int n) {
  for (int currentRow = 1; currentRow <= n; currentRow++) {
    printRow(currentRow, n);
  }
}

void timesTable(int n) {
  colHeader(n);
  printContents(n);
}

int getRange(int first, int last) {
  if(first > last) {
    int temp = first;
    first = last;
    last = temp;
  }

  std::cout << "Please enter a value in the range " << first << "..." << last << ": ";
  int inValue;
  bool badEntry;
  do {
    std::cin >> inValue;
    badEntry = (inValue < first || inValue > last);
    if(badEntry) {
      std::cout << inValue << " is not in the range " << first << "..." << last << '\n';
      std::cout << "Please try again: ";
    }
  } while(badEntry);
  return inValue;
}

int main() {
  int size = getRange(1,18);
  timesTable(size);
}
