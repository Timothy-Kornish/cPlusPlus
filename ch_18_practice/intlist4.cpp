#include "intlist4.h"
#include <iostream>
#include <utility>


Intlist4::Node::Node(int n): data(n), next(nullptr) {
  std::cout << "Creating node " << data << ", Location in memory:  ("
            << reinterpret_cast<uintptr_t>(this) << ")\n";
}

Intlist4::Node::~Node() {
  std::cout << "Destroying node " << data << "  ("
            << reinterpret_cast<uintptr_t>(this) << ")\n";
}

Intlist4::Intlist4(): head(nullptr), tail(nullptr), len(0) {}

Intlist4::Intlist4(const Intlist4& other): head(nullptr), tail(nullptr), len(0) {
  for (auto cursor = other.head; cursor; cursor = cursor->next) {
    insert(cursor->data);
  }
}

Intlist4& Intlist4::operator=(const Intlist4& other) {
  Intlist4 temp(other);

  std::swap(head, temp.head);
  std::swap(tail, temp.tail);
  std::swap(len, temp.len);

  return *this;
}

Intlist4::~Intlist4() { clear(); }

void Intlist4::insert(int n) {
  Intlist4::Node *new_node = new Node(n);
  if(tail) {
    tail->next = new_node;
    tail = new_node;
  }
  else {
    head = tail = new_node;
  }
  len++;
}

void Intlist4::print() const {
  for (auto cursor = head; cursor; cursor = cursor->next) {
    std::cout << cursor->data << ' ';
  }
  std::cout << '\n';
}

void Intlist4::clear() {
  auto cursor = head;
  while(cursor) {
    auto temp = cursor;
    cursor = cursor->next;
    delete temp;
  }
  head = tail = nullptr;
  len = 0;
}

int Intlist4::length() const {
  return len;
}
