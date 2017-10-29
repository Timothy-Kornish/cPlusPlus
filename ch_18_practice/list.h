#ifndef LIST_H_
#define LIST_H_

class Intlist2 {

  struct Node {
    int data;
    Node *next;
    Node(int d);
  };

  Node *head;
  Node *tail;

  int len;

public:

  Intlist2();
  ~Intlist2();

  void insert(int n);
  void print() const;
  void clear();
  int length() const;
};

#endif
