#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>

// new syntax for c++ 11 compiler "g++ -std=c++11 <filename>""

template <typename Iter, typename T>
int count_value(Iter iter_begin, Iter iter_end, const T& seek) {
  int count = 0;
  for (auto cursor = iter_begin; cursor != iter_end; cursor++) {
    if (*cursor == seek) {
      count++;
    }
  }
  return count;
}

int main() {
  std::cout << "---Vector of integers--------------\n";
  std::vector<int> a;
  a.push_back(34), a.push_back(5), a.push_back(12), a.push_back(5);
  a.push_back(8), a.push_back(5), a.push_back(11), a.push_back(2);

  std::cout << count_value(std::begin(a), std::end(a), 5) << '\n';
  a = {};
  std::cout << count_value(std::begin(a), std::end(a), 5) << '\n';
  std::cout << count_value(std::begin(a), std::end(a), 8) << '\n';

  std::cout << "---STL array of integers-----------\n";
  std::array<int, 8> arr {34, 5, 12, 5, 8, 5, 11, 2};
  std::cout << count_value(std::begin(arr), std::end(arr), 5) << '\n';
  arr = {};
  std::cout << count_value(std::begin(arr), std::end(arr), 5) << '\n';
  std::cout << count_value(std::begin(arr), std::end(arr), 8) << '\n';

  std::cout << "---Primitive C array of integers-----\n";
  int carr[] = {34, 5, 12, 5, 8, 5, 11, 2};
  std::cout << count_value(std::begin(carr), std::end(carr), 5) << '\n';
  std::cout << count_value(std::begin(carr), std::end(carr), 8) << '\n';

  std::cout << "---Vector of strings---------------\n";
 // Test with a vector of strings
  std::vector<std::string> b;
  b.push_back("mae"), b.push_back("al"), b.push_back("pat"), b.push_back("mel");
  b.push_back("al"), b.push_back("ray"), b.push_back("al");
  std::cout << count_value(std::begin(b), std::end(b), "al") << '\n';
  b = {};
  std::cout << count_value(std::begin(b), std::end(b), "al") << '\n';
  std::cout << count_value(std::begin(b), std::end(b), "pat") << '\n';

  std::cout << "---Linked list of strings----------\n";
  std::list<std::string> lst;
  lst.push_back("mae"), lst.push_back("al"), lst.push_back("pat"), lst.push_back("mel");
  lst.push_back("al"), lst.push_back("ray"), lst.push_back("al");
  std::cout << count_value(std::begin(lst), std::end(lst), "al") << '\n';
  lst = {};
  std::cout << count_value(std::begin(lst), std::end(lst), "al") << '\n';
  std::cout << count_value(std::begin(lst), std::end(lst), "pat") << '\n';


  std::cout << "---Primitive C array of Points-----\n";
  struct Point {
    int x;
    int y;
    bool operator==(const Point& other) {
      return x == other.x && y == other.y;
    }
    Point(int x, int y): x(x), y(y) {}
  };
   // Test with a primitive array of Point objects
  Point pts[] =  {{5, 3}, {0, 0}, {5, 3}, {3, 5}, {2, 1}};
  std::cout << count_value(std::begin(pts), std::end(pts), Point(5, 3))
            << '\n';
  std::cout << count_value(std::begin(pts), std::end(pts), Point(3, 5))
            << '\n';
  std::cout << count_value(std::begin(pts), std::end(pts), Point(2, 3))
            << '\n';
}
