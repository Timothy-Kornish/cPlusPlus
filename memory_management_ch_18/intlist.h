#ifndef INTLIST_H_
#define INTLIST_H_

class Intlist1 {
  struct Node {
    int data;
    Node *next;
    Node(int d);
  };

  Node *head;
  Node *tail;

  int length(Node *p) const;
  void dispose(Node *p);
public:

  Intlist1();
  void insert(int n);
  void print() const;
  int length() const;
  void clear();
};

#endif
