#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

#include "uniformRandom.h"

int main() {
  const int SIZE = 250000;

  std::vector<int> v;
  std::set<int> s;

  for (int i = 0; i < SIZE; i++)
    v.push_back(i);
  for (int i = 0; i < SIZE; i++)
    s.insert(i);

  UniformRandomGenerator gen(0, SIZE - 1);
  std::vector<int> search_values;
  for (int i = 0; i < SIZE; i++)
    search_values.push_back(gen());
  clock_t start_time, stop_time;

  start_time = clock();
  for (int i = 0; i < SIZE; i++) {
    int seek = search_values[i];
    std::find(std::begin(v), std::end(v), seek);
  }
  stop_time = clock();

  std::cout << "Vector time: " << (stop_time - start_time) / (CLOCKS_PER_SEC/1000) << " msec" << '\n';
  start_time = clock();
  for (int i = 0; i < SIZE; i++) {
    int seek = search_values[i];
    s.find(seek);
  }
  stop_time = clock();
  std::cout << "Set time: " << (stop_time - start_time) / (CLOCKS_PER_SEC/1000) << " msec" << '\n';

}
