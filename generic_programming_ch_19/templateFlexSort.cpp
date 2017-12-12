#include <iostream>
#include <string>
#include <vector>
#include <utility>

template <typename T>
bool less_than(const T& a, const T& b) {
  return a < b;
}

template <typename T>
bool greater_than(const T& a, const T& b) {
  return a > b;
}

template <class T>
void selection_sort(std::vector<T>& vec, bool (*compare)(const T&, const T&)) {
  int n = vec.size();
  for (int i = 0; i < n - 1; i++) {
    int small = i;
    for (int j = i + 1; j < n; j++) {
      if (compare(vec[j], vec[small])) {
        small = j;
      }
    }
    if (i != small) {
      std::swap(vec[i], vec[small]);
    }
  }
}

template <typename T>
void print(const std::vector<T>& vec) {
  int n = vec.size();
  std::cout << '{';
  if (n > 0 ) {
    std::cout << vec[0];
    for (int i = 1; i < n; i++) {
      std::cout << ", " << vec[i];
    }
  }
  std::cout << "}\n";
}

int main() {
  std::vector<int> list;
  std::vector<std::string> words;

  list.push_back(23), list.push_back(-3), list.push_back(4), list.push_back(215);
  list.push_back(0), list.push_back(234), list.push_back(3), list.push_back(2);
  list.push_back(13), list.push_back(36), list.push_back(88);

  words.push_back("tree"), words.push_back("girl"), words.push_back("boy");
  words.push_back("apple"), words.push_back("dog"), words.push_back("cat");
  words.push_back("bird");

  std::cout << "Original:   ";
  print(list);
  std::cout << '\n';
  selection_sort(list, less_than<int>);
  std::cout << "Ascending:  ";
  print(list);
  std::cout << '\n';
  selection_sort(list, greater_than<int>);
  std::cout << "Descending: ";
  print(list);
  std::cout << '\n';

  std::cout << "-------------------------------\n";

  std::cout << "Original:   ";
  print(words);
  std::cout << '\n';
  selection_sort(words, less_than<std::string>);
  std::cout << "Ascending:  ";
  print(words);
  std::cout << '\n';
  selection_sort(words, greater_than<std::string>);
  std::cout << "Descending: ";
  print(words);
  std::cout << '\n';
}
