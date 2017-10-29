#include <iostream>
#include <iomanip>

int count() {
  static int cnt = 0;
  return ++cnt;
}

int counteth() {
  int cnt = 0;
  return ++cnt;
}

int main() {
  std::cout << "static variable staying in memory: ";
  for (int i = 0; i < 10; i++) {
    std::cout << count() << "  ";
  }
  std::cout << "\nNon-static variable reseting in memory: ";
  for (int i = 0; i < 10; i++) {
    std::cout << counteth() << "  ";
  }
  std::cout << '\n';
}
