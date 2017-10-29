#include <iostream>
#include "timerModule.h"

int main() {
  char letter;
  std::cout << "Enter a character: ";
  start_timer();
  std::cin >> letter;
  stop_timer();
  std::cout << elapsed_time() << " seconds\n";
}
