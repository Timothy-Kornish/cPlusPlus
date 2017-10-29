#include <iostream>
#include <vector>

void print(const std::vector<int>& a) {
  int n = a.size();
  std::cout << '{';
  if (n > 0) {
    std::cout << a[0];
    for (int i = 1; i < n; i++) {
      std::cout << ", " << a[i];
    }
  }
  std::cout << '}';
}

void permute(std::vector<int>& a, int begin, int end) {
  if (begin == end) {
    print(a);
    std::cout << '\n';
  }
  else {
    for (int i = begin; i <= end; i++) {
      std::swap(a[begin], a[i]);

      permute(a, begin + 1, end);

      std::swap(a[begin], a[i]);
    }
  }
}

int main() {
  int number;
  std::cout << "Please enter number of values to permute: ";
  std::cin >> number;

  std::vector<int> list(number);

  for (int i = 0; i < number; i++) {
    list[i] = i;
  }

  print(list);
  std::cout << "\n----------\n";
  permute(list, 0, number - 1);
  std::cout << "\n----------\n";
  print(list);
}
