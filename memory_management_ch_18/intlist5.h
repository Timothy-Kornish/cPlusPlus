#ifndef INTLIST5_H_
#define INTLIST5_H_

class Intlist5 {

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

  Intlist5();
  ~Intlist5();

  Intlist5(const Intlist5& other);
  Intlist5(Intlist5&& other);

  Intlist5& operator=(const Intlist5& other);
  Intlist5& operator=(Intlist5&& other);

  void insert(int n);
  void print() const;
  int length() const;
  void clear();
};

#endif
