#include <iostream>

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << '\n';
}

int sum(int a[], int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result += a[i];
  }
  return result;
}

int main() {
  int list[] = {2, 4, 6, 8}; // this is an array, no square brackets.

  print(list, 4);
  std::cout << sum(list, 4) << '\n';

  for (int i = 0; i < 4; i++) {
    list[i] = 0;
  }

  print(list, 4);
  std::cout << sum(list, 4) << '\n';
}
