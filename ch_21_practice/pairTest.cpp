#include <iostream>
#include <string>
#include <tuple>

int main() {
  std::string word;
  int number;
  double quantity;

  std::pair<std::string, double> t1 {"Bob", 9.5};

  std::tie(word, quantity) = t1;

  std::cout << "word = " << word << ", quantity = " << quantity << '\n';

  auto t2 = std::make_pair("Eve", 22);

  word = std::get<0>(t2);
  number = std::get<1>(t2);

  std::cout << "word = " << word << ", quantity = " << quantity << '\n';

  std::string name = "Jo";
  int age = 12;

  auto t3 = std::make_pair(name + "-ann", 2 * age);

  word = t3.first;
  number = t3.second;

  std::cout << "word = " << word << ", quantity = " << quantity << '\n';
}
