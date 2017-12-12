#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <utility>
#include <memory>

template <typename T>
class LinkedList {

  struct Node {
    T data;
    std::shared_ptr<Node> next;
    Node(const T& item): data(item), next(nullptr) {
      std::cout << "Creating node " << data << "  ("
                << reinterpret_cast<uintptr_t>(this) << '\n';
    }
    ~Node() {
      std::cout << "Destroying node " << data << "  ("
                << reinterpret_cast<uintptr_t>(this) << '\n';
    }
    Node(const Node&) = default;
    Node(Node&&) = default;
    Node& operator=(const Node&) = default;
    Node& operator=(Node&&) = default;
  };

  std::shared_ptr<Node> head;
  std::shared_ptr<Node> tail;

  int len;

public:

  LinkedList(): head(nullptr), tail(nullptr), len(0) {}

  LinkedList(const LinkedList& other): head(nullptr), tail(nullptr), len(0) {
    for (auto cursor = other.head; cursor; cursor = cursor->next) {
      insert(cursor->data);
    }
  }

  LinkedList(LinkedList&& temp): head(nullptr), tail(nullptr), len(0) {
    std::swap(head, temp.head);
    std::swap(tail, temp.tail);
    std::swap(len, temp.len);
  }

  LinkedList& operator=(const LinkedList& other) {
    LinkedList temp(other);

    std::swap(head, temp.head);
    std::swap(tail, temp.tail);
    std::swap(len, temp.len);

    return *this;

  }

  LinkedList& operator=(LinkedList&& temp) {
    std::swap(head, temp.head);
    std::swap(tail, temp.tail);
    std::swap(len, temp.len);

    return *this;
  }

  ~LinkedList() {
    clear();
  }

  void insert(const T& item) {
    auto new_node = std::make_shared<LinkedList::Node>(item); // will cause error
   if(tail) {
     tail->next = new_node;
     tail = new_node;
   }
   else {
     head = tail = new_node;
   }
   len++;
  }

  bool remove(const T& item) {
    auto cursor = head;
    auto prev = head;

    while (cursor && cursor->data != item) {
      prev = cursor;
      cursor = cursor->next;
    }
    if (!cursor) {
      return false;
    }

    if (head == tail) {
      head = tail = nullptr;
    }
    else if (cursor == head) {
      head = head->next;
    }
    else {
      prev->next = cursor->next;
    }
    if (cursor == tail) {
      tail = prev;
    }

    len--;
    return true;
  }

  void print() const {
    for (auto cursor = head; cursor; cursor = cursor->next) {
      std::cout << cursor->data << ' ';
    }
    std::cout << '\n';
  }

  int length() const {
    return len;
  }

  void clear() {
    auto cursor = head;
    while (cursor) {
      auto temp = cursor;
      cursor = cursor->next;
      temp->next = nullptr;
    }
    head = tail = nullptr;
    len = 0;
  }

  template <typename V>
  friend std::ostream& operator<<(std::ostream& os, const LinkedList<V>& list);

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
  os << '{';
  if (list.length() > 0) {
    auto cursor = list.head;
    os << cursor->data;
    cursor = cursor->next;
    while (cursor) {
      os << ", " << cursor->data;
      cursor = cursor->next;
    }
  }
  os << '}';
  return os;
}

#endif
