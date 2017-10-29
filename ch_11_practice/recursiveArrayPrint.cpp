#include <iostream>

void iterativePrint(const int *a, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ' ';
  }
}

void recursivePrint(const int *a, int n) {
  if (n > 0) {
    std::cout << *a << ' ';
    recursivePrint(a + 1, n - 1);
  }
}

int main() {
  int list[] = {23, -3, 4, 215, 0, -3, 2, 23, 100, 88, -10 };
  iterativePrint(list, 11);
  std::cout << "\n---------\n";
  recursivePrint(list, 11);
}
