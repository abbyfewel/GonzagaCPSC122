#include "linked_list.hpp"
#include <iostream>

Node::~Node() {
    if (next != nullptr) {
        delete next;
        next = nullptr; // Set next to nullptr after deletion
    }
}

LinkedList:: ~LinkedList() {
  if (head != nullptr) {
    delete head;
    head = nullptr;
  }
}

Node* LinkedList :: get_head() const {
  return head;
}

bool LinkedList::push_back(int value) {
 if (head == nullptr) {
    head = new Node;
    head-> next = nullptr;
    head-> value = value;
 } else {
   Node* iter = head;
   while(iter -> next !=nullptr) {
     iter = iter->next;
   }
   iter->next = new Node;
   iter->next->next = nullptr;
   iter->next->value = value;
 }
  return true;
}

bool LinkedList:: push_front(int value) {
  Node* new_node = new Node;
  new_node->value = value;
  new_node->next=head;
  head = new_node;
  return true;
}

bool LinkedList::is_empty() const {
  return head == nullptr;
}

int LinkedList::size() const {
  if(is_empty()) {
    return 0;
  }
  Node* iter=head;
  int counter = 0;
  while (iter ->next != nullptr) {
    counter++;
    iter = iter->next;
  }
  return counter+1;
}

bool LinkedList::insert(int index, int value) {
  if(index == 0) {
    return push_front(value);
  } 
  if (index > size()) {
    return false;
  }
  Node* iter = head;
  int counter = 1;
  for(; counter < index-1; counter++) {
    iter = iter->next;
  }
  Node* new_node = new Node;
  new_node->value =value;
  new_node->next = iter->next;
  iter->next = new_node;
  return true;
}

bool LinkedList::remove(int index) {
  if (index < size() && index >= 0) {
    if (index ==0) {
      Node* temp = head;
      head = head->next;
      temp->next = nullptr;
      delete temp;
      return true;
    }
    Node* iter = head;
    int count = 0;
    for(; count < index -1; count++) {
      iter = iter->next;
    }
    Node* temp = iter->next;
    iter->next = temp->next; //could also do iter->next = iter->next->next; here
    temp->next = nullptr;
    delete temp;
    return true;
  } else {
    return false;
  }  
}

bool LinkedList::remove_value(int value) {
  if (is_empty()) {
    return false;
  }
  for (Node* iter = head; iter->next != nullptr; iter = iter->next){
    if (iter->next->value == value) {
      Node* temp = iter->next;
      iter->next = iter -> next ->next;
      temp->next = nullptr;
      delete temp;
      return true;
    } 
  }
  return false;
}

Stack::Stack() {
  lst = LinkedList();
}

bool Stack:: push (int value) {
  return lst.push_front(value);
}

int Stack::pop() {
  if (lst.is_empty()) {
    throw std::out_of_range(" ");
  } 
  try {
    int ret = lst.at(0);
    lst.remove(0);
    return ret;
  }
catch {
    throw std::out_of_range(" ");
  }
  
}
