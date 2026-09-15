#include <cassert>
#include <print>
#include <stdexcept>

class Node {
public:
  Node *next;
  int data;

  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

class LinkedList {
public:
  Node *head;

  LinkedList() { head = nullptr; }

  void append(int data) {
    if (head == nullptr) {
      head = new Node(data);
      return;
    }

    Node *cur = head;
    while (cur->next != nullptr) {
      cur = cur->next;
    }

    cur->next = new Node(data);
  }

  int get(int index) {
    Node *cur = head;
    if (cur == nullptr) {
      throw std::out_of_range("Index out of bounds");
    }
    for (int i = 0; i < index; i++) {
      if (cur->next == nullptr) {
        throw std::out_of_range("Index out of bounds");
      }
      cur = cur->next;
    }

    return cur->data;
  }
};

int main() {
  LinkedList ll;

  ll.append(1);
  assert(("Single item appended", ll.head->data == 1));

  ll.append(2);
  assert(("First item untouched", ll.head->data == 1));
  assert(("Second item appended", ll.head->next->data == 2));

  assert(("Get first item", ll.get(0) == 1));
  assert(("Get second item", ll.get(1) == 2));

  try {
    ll.get(2);
    assert(false && "Should have thrown out_of_range");
  } catch (const std::out_of_range &e) {
  }

  return 0;
}
