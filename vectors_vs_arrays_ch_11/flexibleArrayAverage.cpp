#include <iostream>

int main() {
  double sum = 0.0;
  double *numbers;
  int size;

  std::cout << "Please enter the number of values to process: ";
  std::cin >> size;

  if (size > 0) {
    std::cout << "Please enter " << size << "numbers: ";
    numbers = new double[size];

    for (int i = 0; i < size; i++) {
      std::cin >> numbers[i];
      sum += numbers[i];
    }
    std::cout << "The average of ";
    for (int i = 0; i < size - 1; i++) {
      std::cout << numbers[i] << ", ";
    }
    std::cout << numbers[size -1] << " is " sum/size << '\n';
    delete [] numbers;
  }
}
