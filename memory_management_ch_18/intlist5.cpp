#include "intlist5.h"
#include <iostream>
#include <algorithm>

Intlist5::Node::Node(int n): data(n), next(nullptr) {
  std::cout << "Creating node " << data << "  ("
            << reinterpret_cast<uintptr_t>(this) << ")\n";
}

Intlist5::Node::~Node() {
  std::cout << "Destroying node " << data << "  ("
            << reinterpret_cast<uintptr_t>(this) << ")\n";
}

Intlist5::Intlist5(): head(nullptr), tail(nullptr), len(0) {}

Intlist5::Intlist5(const Intlist5& other):
                   head(nullptr), tail(nullptr), len(0) {
  for (auto cursor = other.head; cursor; cursor = cursor->next) {
    insert(cursor->data);
  }
}

Intlist5::Intlist5(Intlist5&& temp):
                   head(nullptr), tail(nullptr), len(0) {
  std::swap(head, temp.head);
  std::swap(tail, temp.tail);
  std::swap(len, temp.len);
}

Intlist5& Intlist5::operator=(const Intlist5& other) {
  Intlist5 temp(other);

  std::swap(head, temp.head);
  std::swap(tail, temp.tail);
  std::swap(len, temp.len);

  return *this;
}

Intlist5& Intlist5::operator=(Intlist5&& temp) {

  std::swap(head, temp.head);
  std::swap(tail, temp.tail);
  std::swap(len, temp.len);

  return *this;
}

Intlist5::~Intlist5() { clear(); }

void Intlist5::insert(int n) {
  Intlist5::Node *new_node = new Node(n);
  if (tail) {
    tail->next = new_node;
    tail = new_node;
  }
  else {
    head = tail = new_node;
  }
  len++;
}

void Intlist5::print() const {
  for (auto cursor = head; cursor; cursor = cursor->next) {
    std::cout << cursor->data << ' ';
  }
  std::cout << '\n';
}

int Intlist5::length() const {
  return len;
}

void Intlist5::clear() {
  auto cursor = head;
  while (cursor) {
    auto temp = cursor;
    cursor = cursor->next;
    delete temp;
  }
  head = tail = nullptr;
  len = 0;
}
