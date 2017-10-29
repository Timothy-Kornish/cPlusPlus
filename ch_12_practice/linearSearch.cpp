#include <iostream>
#include <vector>
#include <iomanip>

int locate(const std::vector<int>& a, int seek) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] == seek) {
      return i; // returns i, and breaks loop
    }
  }
  return -1; // -1 means element not found
}

void format(int i) {
  if (i > 9999) {
    std::cout << "****" << '\n';
  } else {
    std::cout << std::setw(4) << i;
  }
}

void print(const std::vector<int>& v) {
  for (int i : v) {
    format(i);
  }
}

void display(const std::vector<int>& a, int value) {
  int position = locate(a, value);
  if (position >= 0) {
    print(a);
    std::cout << '\n';
    position = 4 * position + 7;
    std::cout << std::setw(position);
    std::cout << "   ^   " << '\n';
    std::cout << std::setw(position);
    std::cout << "   |   " << '\n';
    std::cout << std::setw(position);
    std::cout << "   +-- " << value << '\n';
  }
  else {
    std::cout << value << " not in list: ";
    print(a);
    std::cout << '\n';
  }
  std::cout << "======" << '\n';
}

int main() {
  std::vector<int> list;
  list.push_back(100);
  list.push_back(23);
  list.push_back(4);
  list.push_back(-3);
  list.push_back(44);
  list.push_back(80);
  list.push_back(11);
  list.push_back(110);
  list.push_back(21);
  list.push_back(239);

  display(list, 23);
  display(list, 21);
  display(list, 70);
  display(list, 100);
  display(list, 110);
}
