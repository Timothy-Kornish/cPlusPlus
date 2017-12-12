#include "intlist3.h"
#include <iostream>


Intlist3::Node::Node(int n): data(n), next(nullptr) {
  std::cout << "Creating node " << data << ", Location in memory:  ("
            << reinterpret_cast<uintptr_t>(this) << ")\n";
}

Intlist3::Node::~Node() {
  std::cout << "Destroying node " << data << "  ("
            << reinterpret_cast<uintptr_t>(this) << ")\n";
}

Intlist3::Intlist3(): head(nullptr), tail(nullptr), len(0) {}

Intlist3::~Intlist3() {
  clear();
}

void Intlist3::insert(int n) {
  Intlist3::Node *new_node = new Node(n);
  if(tail) {
    tail->next = new_node;
    tail = new_node;
  }
  else {
    head = tail = new_node;
  }
  len++;
}

void Intlist3::print() const {
  for (auto cursor = head; cursor; cursor = cursor->next) {
    std::cout << cursor->data << ' ';
  }
  std::cout << '\n';
}

void Intlist3::clear() {
  auto cursor = head;
  while(cursor) {
    auto temp = cursor;
    cursor = cursor->next;
    delete temp;
  }
  head = tail = nullptr;
  len = 0;
}

int Intlist3::length() const {
  return len;
}
