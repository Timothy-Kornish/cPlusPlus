#include <iostream>
#include <vector>

int main() {
  int arr[] = {10, 20, 30, 40, 50}; // [] brackets don't work, needs curly braces {}
  for (auto iter = std::begin(arr); iter != std::end(arr); iter++) {
    std::cout << *iter << ' ';
  }
  std::cout << '\n';
}
