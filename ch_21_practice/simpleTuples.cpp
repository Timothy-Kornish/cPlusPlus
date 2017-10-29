#include <iostream>
#include <string>
#include <tuple>
#include <cmath>

int main() {
  std::string word;
  int number;
  double quantity;
  bool truthy;

  std::tuple<std::string, int, double, bool> t1 {"Bob", 4, 9.5, true};

  std::tie(word, number, quantity, truthy) = t1;

  std::cout << "word = " << word << ", number = " << number << ", quantity = "
            << quantity << ", truthy = " << truthy << '\n';

  auto t2 = std::make_tuple("Eve", 22, 8.3, true);

  std::tie(word, number, quantity, truthy) = t2;

  std::cout << "word = " << word << ", number = " << number << ", quantity = "
            << quantity << ", truthy = " << truthy << '\n';

  std::string name = "Jan";
  int age = 12;
  double amount = 50.2;
  bool loyal = false;

  auto t3 = std::make_tuple(name, age * 2, std::sqrt(amount), !loyal);

  word = std::get<0>(t3);
  number = std::get<1>(t3);
  quantity = std::get<2>(t3);
  truthy = std::get<3>(t3);

  std::cout << "word = " << word << ", number = " << number << ", quantity = "
            << quantity << ", truthy = " << truthy << '\n';
}
