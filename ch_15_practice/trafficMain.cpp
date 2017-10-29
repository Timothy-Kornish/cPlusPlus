#include <iostream>
#include "trafficLight.h"

void print(TrafficLight lt) {

   SignalColor color = lt.get_color();
   std::cout << "+-----+\n";
   std::cout << "|     |\n";
   if (color == SignalColor::Red)
       std::cout << "| (R) |\n";
   else
       std::cout << "| ( ) |\n";
   std::cout << "|     |\n";
   if (color == SignalColor::Yellow)
       std::cout << "| (Y) |\n";
   else
       std::cout << "| ( ) |\n";
   std::cout << "|     |\n";
   if (color == SignalColor::Green)
       std::cout << "| (G) |\n";
   else
       std::cout << "| ( ) |\n";
   std::cout << "|     |\n";
   std::cout << "+-----+\n";

}

int main() {
  TrafficLight light(SignalColor::Green);
  print(light);
  light.change();
  std::cin.get();
}
