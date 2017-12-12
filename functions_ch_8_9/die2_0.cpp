#include <iostream>
#include <cstdlib>
#include <ctime>

void initializeDie() {
  srand(static_cast<unsigned>(time(0)));
}

void showDie(int num) {
  std::cout << "+-------+\n";
  switch(num) {
    case 1:
      std::cout << "|       |\n";
      std::cout << "|   *   |\n";
      std::cout << "|       |\n";
      break;
    case 2:
      std::cout << "| *     |\n";
      std::cout << "|       |\n";
      std::cout << "|     * |\n";
      break;
    case 3:
      std::cout << "|     * |\n";
      std::cout << "|   *   |\n";
      std::cout << "| *     |\n";
      break;
    case 4:
      std::cout << "| *   * |\n";
      std::cout << "|       |\n";
      std::cout << "| *   * |\n";
      break;
    case 5:
      std::cout << "| *   * |\n";
      std::cout << "|   *   |\n";
      std::cout << "| *   * |\n";
      break;
    case 6:
      std::cout << "| * * * |\n";
      std::cout << "|       |\n";
      std::cout << "| * * * |\n";
      break;
    default:
      std::cout <<  " ***  Error: illegal die value ***\n";
      break;
  }
  std::cout << "+-------+\n\n";
}

int roll() {
  return rand() % 6 + 1;
}

int main() {

  initializeDie();

  for (int i = 0; i < 5; i++) {
    showDie(roll());
  }
}
