#include <print>
#include <cassert>

class Node {
public:
  Node* next;
  int data;

  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class LinkedList {
public:
  Node* head;

  LinkedList() {
    head = nullptr;
  }

  void append(int data) {
    if (head == nullptr) {
      head = new Node(data);
      return;
    }

    Node* cur = head;
    while (cur->next != nullptr) {
      cur = cur->next;
    }


    cur->next = new Node(data);
  }

  int get(int index) {
    Node* cur = head;
    for (int i = 0; i < index; i++) {
      cur = head->next;
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

  return 0;
}