#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int data, Node *next): data(data), next(next) {}
};

int main() {
  Node n4(3, nullptr), n3(0, &n4), n2(10, &n3), n1(23, &n2);

  for (Node *cursor = &n1; cursor != nullptr; cursor = cursor->next) {
    std::cout << cursor->data << ' ';
  }
  std::cout << '\n';

}
