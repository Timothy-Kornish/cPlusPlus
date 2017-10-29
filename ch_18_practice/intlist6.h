#ifndef INTLIST6_H_
#define INTLIST6_H_

#include <memory>

class Intlist6 {

  struct Node {
    int data;
    std::shared_ptr<Node> next;
    Node(int d);
    Node(const Node&) = default;
    Node(Node&&) = default
    ~Node();
    Node& operator=(const Node&) = default;
    Node& operator=(Node&&) = default;
  };

  std::shared_ptr<Node> head;
  std::shared_ptr<Node> tail;

  int len;

public:

  Intlist6();
  ~Intlist6();

  Intlist6(const Intlist6& other);
  Intlist6(Intlist6&& other);

  Intlist6& operator=(const Intlist6& other);
  Intlist6& operator=(Intlist6&& other);

  void insert(int n);
  void print() const;
  int length() const;
  void clear();
};

#endif
