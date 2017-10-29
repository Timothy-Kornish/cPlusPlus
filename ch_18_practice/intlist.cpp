#include "intlist.h"
#include <iostream>

Intlist1::Node::Node(int n): data(n), next(nullptr) {}

int Intlist1::length(Intlist1::Node *p) const {
  if (p) {
    return 1 + length(p->next);
  }
  else {
    return 0;
  }
}
void Intlist1::dispose(Intlist1::Node *p) {
  if (p) {
    dispose(p->next);
    delete p;
  }
}

Intlist1::Intlist1(): head(nullptr), tail(nullptr) {}

void Intlist1::insert(int n) {
  Intlist1::Node *new_node = new Node(n);
  if(tail) {
    tail->next = new_node;
    tail = new_node;
  }
  else {
    head = tail = new_node;
  }
}

void Intlist1::print() const {
  for (auto cursor = head; cursor; cursor = cursor->next) {
    std::cout << cursor->data << ' ';
  }
  std::cout << '\n';
}

void Intlist1::clear() {
  dispose(head);
  head = tail = nullptr;
}

int Intlist1::length() const {
  return length(head);
}
