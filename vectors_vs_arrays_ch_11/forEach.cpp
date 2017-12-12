#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers(5);
  numbers[1] = 1;
  numbers[2] = 2;
  numbers.push_back(5); // creates 6th element in vector at index 5;
  numbers.push_back(6); // creates 7th element at end of vector
  numbers.pop_back(); // removes last element in vector
  for (int n : numbers) {
    std::cout << n << '\n';
  }
  std::cout << "-------------\n";

  std::vector<double> vec(10);
  std::cout << "Please enter 10 numbers: ";

  for (double& elem : vec) {
    std::cin >> elem;
  }

  for (double elem : vec) {
    std::cout << elem << '\n';
  }
}
