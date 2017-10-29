#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int get_int() {
  std::string input;
  std::cin >> input;
  int result = stoi(input);
  return result;
}

int main() {
  std::vector<int> a { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
  try { 
    int n = a.size();
    std::cout << "Enter index in the range 0..." << n - 1 << ": ";
    int i = get_int();
    std::cout << "Index entered: " << i << '\n';
    std::cout << "a[" << i << "] = " << a.at(i) << '\n';
  }
  catch (std::out_of_range&)  {
    std::cout << "Index provided is out of range\n";
  }
  catch (std::invalid_argument&) {
    std::cout << "Index provided is not an integer\n";
  }
  catch (...) {
    std::cout << "Unknown error\n";
  }
}
