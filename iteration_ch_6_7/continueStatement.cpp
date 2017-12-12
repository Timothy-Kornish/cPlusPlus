#include <iostream>

int main() {
  int input, sum = 0;
  bool done = false;

  while(!done){
    std::cout << "Enter positive inter (999 quits program): ";
    std::cin >> input;

    if (input < 0) {
      std::cout << "Negative value " << input << " ignored\n";
      continue; // without, negative number will be added to sum; 
    }
    if (input != 999) {
      std::cout << "Tallying " << input << '\n';
      sum += input;
    }
    else {
      done = (input == 999);
    }
  }
  std::cout << "sum = " << sum << '\n';
}
