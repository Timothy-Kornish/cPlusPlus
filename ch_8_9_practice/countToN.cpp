#include <iostream>

void countToN(int n) {
  for (int index = 1; index <= n; index++){
    std::cout << index << " bat ha ha ha\n";
  }
}

int main() {
  int input;
  std::cout << "How high would you like to count? ";
  std::cin >> input;
  countToN(input);
}
