#include <iostream>

const int MAX_NUMBER_OF_ENTRIES = 1000000; // 1,000,000
double numbers[MAX_NUMBER_OF_ENTRIES];

int main() {
  double sum = 0.0;
  int size;

  std::cout << "Please enter number of values to process: ";
  std::cin >> size;

  if (size > 0) {
    std::cout << "Please enter " << size << " numbers: ";

    for (int i = 0; i < size; i++) {
      std::cin >> numbers[i];
      sum += numbers[i];
    }
    std::cout << "The average of ";
    for (int i = 0; i < size - 1; i++) {
      std::cout << numbers[i] << ", ";
    }
    std::cout << numbers[size - 1] << " is " << sum/size << '\n';
  }
}
