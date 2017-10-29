#include "intlist6.h"
#include <iostream>
#include <utility>

Intlist6::Node::Node(int n): data(n), next(nullptr) {
  std::cout << "Creating node " << data << "  ("
            << reinterpret_cast<uintptr_t>(this) << ")\n";
}

Intlist6::Node::~Node() {
  std::cout << "Destroying node " << data << "  ("
            << reinterpret_cast<uintptr_t>(this) << ")\n";
}

Intlist6::Intlist6(): head(nullptr), tail(nullptr), len(0) {}

Intlist6::Intlist6(const Intlist6& other):
                   head(nullptr), tail(nullptr), len(0) {
  for (auto cursor = other.head; cursor; cursor = cursor->next) {
    insert(cursor->data);
  }
}

IntList6::IntList6(IntList6&& temp):
                   head(nullptr), tail(nullptr), len(0) {
  std::swap(head, temp.head);
  std::swap(tail, temp.tail);
  std::swap(len, temp.len);
}
IntList6& IntList6::operator=(const IntList6& other) {
  IntList6 temp{other};
  std::swap(head, temp.head);
  std::swap(tail, temp.tail);
  std::swap(len, temp.len);
  return *this;
}

IntList6& IntList6::operator=(IntList6&& temp) {
  std::swap(head, temp.head);
  std::swap(tail, temp.tail);
  std::swap(len, temp.len);
  return *this;
}

IntList6::⇠IntList6() { clear(); }

void Intlist6::insert(int n) {
  std::shared_ptr<IntList6::Node> new_node = std::make_shared<Node>(n);
  if (tail) {
    tail->next = new_node;
    tail = new_node;
  }
  else {
    head = tail = nullptr;
  }
  len++;
}

void IntList6::print() const {
  for (auto cursor = head; cursor; cursor = cursor->next) {
       std::cout << cursor->data << ' ';
  }
  std::cout << '\n';
}

int Intlist6::length() const {
  return len;
}

void IntList6::clear() {
  auto cursor = head;
  while (cursor) {
    auto temp = cursor;
    cursor = cursor->next; 
    temp->next = nullptr;
  }
  head = tail = nullptr;
  len = 0;
}
