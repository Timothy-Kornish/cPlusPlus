#include <iostream>
#include <vector>

int main() {
  double sum = 0.0;
  const int NUMBER_OF_ENTRIES = 5;
  std::vector<double> numbers(NUMBER_OF_ENTRIES);

  std::cout << "Please enter " << NUMBER_OF_ENTRIES << " numbers: ";

  for (int index = 0; index < NUMBER_OF_ENTRIES; index++) {
    std::cin >> numbers[index];
    sum += numbers[index];
  }
  std::cout << "The average of ";
  for (int i = 0; i < NUMBER_OF_ENTRIES - 1; i++) {
    std::cout << numbers[i] << ", ";
  }
  std::cout << numbers[NUMBER_OF_ENTRIES - 1] << " is " << sum/NUMBER_OF_ENTRIES << '\n'; 
}
