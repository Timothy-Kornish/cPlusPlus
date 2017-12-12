#include <iostream>
#include <vector>
#include <iomanip>

int binary_search(const std::vector<int>& a, int seek) {
  int first = 0,
  last = a.size() - 1,
  mid;

  while (first <= last) {
    mid = first + (last - first + 1) / 2;

    if (a[mid] == seek) {
      return mid;
    }
    else if (a[mid] > seek) {
      last = mid - 1;
    }
    else {
      first = mid + 1;
    }
  }
  return -1;
}

void format(int i) {
  if (i > 9999) {
    std::cout << "****\n";
  }
  else {
    std::cout << std::setw(4) << i;
  }
}

void print(const std::vector<int>& v) {
  for (int i : v) {
    format(i);
  }
}

void display(const std::vector<int>& a, int value) {
  int position = binary_search(a, value);
  if (position >= 0) {
    print(a);
    std::cout << '\n';
    position = 4 * position + 7;
    std::cout << std::setw(position) << "   ^   \n";
    std::cout << std::setw(position) << "   |   \n";
    std::cout << std::setw(position) << "   +-- " << value << '\n';
  }
  else {
    std::cout << value << " not found in list: ";
    print(a);
    std::cout << '\n';
  }
  std::cout << "======" << '\n';
}

int main() {
  std::vector<int> evenList, oddList, emptyList;

  evenList.push_back(1);
  evenList.push_back(2);
  evenList.push_back(3);
  evenList.push_back(4);
  evenList.push_back(5);
  evenList.push_back(6);
  evenList.push_back(7);
  evenList.push_back(8);

  oddList.push_back(1);
  oddList.push_back(2);
  oddList.push_back(3);
  oddList.push_back(4);
  oddList.push_back(5);
  oddList.push_back(6);
  oddList.push_back(7);
  oddList.push_back(8);
  oddList.push_back(9);

  for (int i = -1; i <= 10; i++){
    display(evenList,i);
  }
  for (int i = -1; i <= 10; i++){
    display(oddList,i);
  }
  for (int i = -1; i <= 10; i++){
    display(emptyList,i);
  }
}
