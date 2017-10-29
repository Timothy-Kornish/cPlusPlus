#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  srand(static_cast<unsigned>(time(0)));

  for (int index = 0; index < 5; index++) {
    int value = rand() % 6 + 1;

    std::cout << "+-------+\n";
    switch(value) {
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
}
