#include "../HEADER.h"

class Node {
public:
  int data;
  Node *next;

  Node() {
    data = 0;
    next = NULL;
  }

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList() { head = NULL; }

  void push_back(int data) {
    Node *newNode = new Node(data);

    if (head == NULL) {
      head = newNode;
      return;
    }
    Node *temp = head;

    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void push_front(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }

  void pop_front() {
    if (head == NULL) {
      return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  void pop_back() {
    if (head == nullptr) {
      return;
    }

    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }
    Node *temp = head;

    while (temp->next->next != nullptr) {
      temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
  }

  void Print() {
    Node *temp = head;

    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList eep;

  eep.push_back(1);
  eep.push_back(2);
  eep.push_front(3);
  eep.Print();
  eep.pop_front();
  eep.pop_back();
  eep.Print();

  return 0;
}
