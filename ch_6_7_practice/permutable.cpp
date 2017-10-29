#include <iostream>

int main() {
  char first = 'A';

  while (first <= 'C') {
    char second = 'A';
    while (second <= 'C') {
      if (second != first) {
        char third = 'A';
        while (third <= 'C') {
          if (third != first && third != second) {
            std::cout << first << second << third << '\n';
          }
          third++;
        }
      }
      second++;
    }
    first++;
  }
}
