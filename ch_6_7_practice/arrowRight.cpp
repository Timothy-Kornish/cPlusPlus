#include <iostream>

int main() {
   int input, row = 0;
   std::cout << "Please enter a positive integer: ";
   std::cin >> input;

   while (row < input) {
     int count = 0;

     while(count < row + 1) {
       std::cout << "*";
       count++;
     }
     std::cout << '\n';
     row++;
   }
   row--;

   while (row > 0) {
     int count = row;
     while(count > 0 ) {
       std::cout << "*";
       count--;
     }
     std::cout << '\n';
     row--;
   }

}
