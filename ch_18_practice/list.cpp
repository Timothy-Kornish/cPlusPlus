#include "list.h"
#include <iostream>

Intlist2::Node::Node(int n): data(n), next(nullptr) {}

Intlist2::Intlist2(): head(nullptr), tail(nullptr), len(0) {}

Intlist2::~Intlist2() {
  clear();
}

void Intlist2::insert(int n) {
  Intlist2::Node *new_node = new Node(n);
  if(tail) {
    tail->next = new_node;
    tail = new_node;
  }
  else {
    head = tail = new_node;
  }
  len++;
}

void Intlist2::print() const {
  for (auto cursor = head; cursor; cursor = cursor->next) {
    std::cout << cursor->data << ' ';
  }
  std::cout << '\n';
}

void Intlist2::clear() {
  auto cursor = head;
  while(cursor) {
    auto temp = cursor;
    cursor = cursor->next;
    delete temp;
  }
  head = tail = nullptr;
  len = 0;
}

int Intlist2::length() const {
  return len;
}
