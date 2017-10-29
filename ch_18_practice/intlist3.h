#ifndef INTLIST3_H_
#define INTLIST3_H_

class Intlist3 {

  struct Node {
    int data;
    Node *next;
    Node(int d);
    ~Node();
  };

  Node *head;
  Node *tail;

  int len;

public:

  Intlist3();
  ~Intlist3();

  void insert(int n);
  void print() const;
  void clear();
  int length() const;
};

#endif
