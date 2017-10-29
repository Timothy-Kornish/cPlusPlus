#include <iostream>

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << '\n';
}

void clear(int a[], int n) {
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
}

int main() {
  int list[] = {2, 4, 6, 8};
  print(list, 4);
  clear(list, 4);
  print(list, 4);
}