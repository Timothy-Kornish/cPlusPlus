#include <iostream>

int main(){
  double inputFahrenheit, outputCelcius;

  std::cout << "Please enter the temperature in Fahrenheit: ";
  std::cin >> inputFahrenheit;
  outputCelcius = 5.0/9.0 * (inputFahrenheit - 32.0);
  std::cout << "Degrees C = " << outputCelcius << std::endl;
}
