#include <iostream>
#include <iomanip>
#include <random>

int main() {
  std::random_device rdev;

  std::mt19937 mt(rdev());

  std::uniform_int_distribution<int> dist(0, 9999);

  double total5 = 0.0, total9995 = 0.0;
  const int NUMBER_OF_TRIALS = 10;

  for (int trial = 1; trial <= NUMBER_OF_TRIALS; trial++) {
    int count5 = 0, count9995 = 0;
    for (int i = 0; i < 1000000000; i++) {
      int r = dist(mt);
      if (r == 5) {
        count5++;
      }
      else if (r == 9995) {
        count9995++;
      }
    }

    std::cout << "Trial #" << std::setw(2) << trial
              << "  5: " << std::setw(6) << count5
              << "     9995: " << std::setw(6) << count9995 << '\n';
              total5 += count5;
              total9995 += count9995;
  }

  std::cout << "----------------------\n";
  std::cout << "Averages for " << NUMBER_OF_TRIALS << " trials:  5: "
            << std::setw(6) << (total5 / NUMBER_OF_TRIALS) << "  9995: "
            << std::setw(6) << (total9995 / NUMBER_OF_TRIALS) << '\n';
}
