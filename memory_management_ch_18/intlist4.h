#ifndef INTLIST4_H_
#define INTLIST4_H_

class Intlist4 {

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

  Intlist4();
  ~Intlist4();

  Intlist4(const Intlist4& other);

  Intlist4& operator=(const Intlist4& other);

  void insert(int n);
  void print() const;
  void clear();
  int length() const;
};

#endif
