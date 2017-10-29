#include <iostream>
#include <limits>

int main() {
  int x;

  std::cout << "Please enter an integer: ";

  while (!(std::cin >> x)) {
    std::cout << "Bad entry, please try again: ";

    std::cin.clear(); // resets intput object state from error state.

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removes all characters up to last '\n' the compiler sees
    // numeric_limits<std::streamsize>::max() returns max number of characters that the buffer can hold.
  }
  std::cout << "You entered " << x << '\n';
}
