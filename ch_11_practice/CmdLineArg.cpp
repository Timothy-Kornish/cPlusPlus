#include <iostream>
// enter characters in command line after ./a.out

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    std::cout << '[' << argv[i] << "]\n";
  }
}
