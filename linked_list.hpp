#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Node {
  public:
    int value;
    Node* next;
    ~Node();
};

class Stack {
  private: 
    LinkedList lst;
  public:
    Stack();
    bool push (int value);
    int pop();
};

class LinkedList {
  private: 
    Node* head = nullptr;
  public:
    int size() const;
    bool push_back(int value);
    bool push_front(int value);
    bool insert(int index, int value);
    bool remove(int index);
    bool remove_value(int value);
    bool is_empty() const;
    Node* get_head() const;
    ~LinkedList();
};

#endif
