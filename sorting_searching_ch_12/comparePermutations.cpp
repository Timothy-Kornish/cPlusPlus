#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

void print(const std::vector<int>& a) {
  int n = a.size();
  std::cout << "{";
  if (n > 0) {
    for (int i = 1; i < n; i++) {
      std::cout << ", " << a[i];
    }
  }
  std::cout << "}\n";
}

int random(int begin, int end) {
  if (begin >= end) {
    return 0;
  }
  else {
      int range = end - begin;
      return begin + rand() % range;
  }
}

void permute(std::vector<int>& a) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) {
    std::swap(a[i], a[random(i,n)]);
  }
}

void faulty_permute(std::vector<int>& a){
  int n = a.size();
  for (int i = 0; i < n; i++) {
    std::swap(a[i], a[random(0,n)]);
  }
}

int classify(const std::vector<int>& a) {
  switch (100 * a[0] + 10 * a[1] + a[2]) {
    case 123: return 0;
    case 132: return 1;
    case 213: return 2;
    case 231: return 3;
    case 312: return 4;
    case 321: return 5;
    default: return -1;
  }
}

void report(const std::vector<int>& a) {
  std::cout << "1,2,3 appeared: " << a[0] << " times\n";
  std::cout << "1,3,2 appeared: " << a[1] << " times\n";
  std::cout << "2,1,3 appeared: " << a[2] << " times\n";
  std::cout << "2,3,1 appeared: " << a[3] << " times\n";
  std::cout << "3,1,2 appeared: " << a[4] << " times\n";
  std::cout << "3,2,1 appeared: " << a[5] << " times\n";
}

void clear(std::vector<int>& a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
}

int main() {
  srand(static_cast<int>(time(0)));

  std::vector<int> p_tally; // short for permutation_tally
  p_tally.push_back(0), p_tally.push_back(0), p_tally.push_back(0);
  p_tally.push_back(0), p_tally.push_back(0), p_tally.push_back(0);

  std::vector<int> original;
  original.push_back(1), original.push_back(2), original.push_back(3);

  std::vector<int> working;

  const int RUNS = 1000000; // 1,000,000

  std::cout << "--- Random Permute #1 ----\n";
  clear(p_tally);
  for (int i = 0; i < RUNS; i++) {
    working = original;

    permute(working);
    p_tally[classify(working)]++;
  }
  report(p_tally);

  std::cout << "--- Random Permute #2 ----\n";
  clear(p_tally);
  for (int i = 0; i < RUNS; i++) {

    working = original;
    faulty_permute(working);
    p_tally[classify(working)]++;
  }
  report(p_tally);


}
