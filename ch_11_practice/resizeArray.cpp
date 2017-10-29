#include <iostream>

int main() {
   double sum = 0.0;
   double *numbers, input;

   const int CHUNK = 3;
   int size = 0, capacity = CHUNK;

   numbers = new double[capacity];

   std::cout << "Please enter any number of non-negative values (negative value ends the list): ";
   std::cin >> input;

   while (input >= 0) {
     if (size >= capacity) {
       capacity += CHUNK;
       double *temp = new double[capacity];

       for (int i = 0; i < size; i++) {
         temp[i] = numbers[i];
       }
       delete [] numbers;
       numbers = temp;
       std::cout << "Expanding Array size by " << CHUNK << '\n';
     }
     numbers[size] = input;
     size++;
     sum += input;
     std::cin >> input;
   }

   if (size > 0) {
     std::cout << "The average of [";
     for (int i = 0; i < size - 1; i++) {
       std::cout << numbers[i] << ", ";
     }
     std::cout << numbers[size - 1] << "] is " << sum / size << '\n';
   } else {
     std::cout << "No numbers to average.\n";
   }
   delete [] numbers;
}
