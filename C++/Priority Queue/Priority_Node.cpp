#include "Priority_Node.h"

// Constructors
Priority_Node::Priority_Node() {
    this->data = 0;
    this->next = nullptr;
    this->priority = 0;
}


Priority_Node::Priority_Node(int data) {
    this->data = data;
    this->next = nullptr;
    this->priority = 0;
}


Priority_Node::Priority_Node(int data, Priority_Node* next) {
    this->data = data;
    this->next = next;
    this->priority = 0;
}


Priority_Node::Priority_Node(int data, int priority) {
    this->data = data;
    this->next = nullptr;
    this->priority = priority;
}


// Destructor
Priority_Node::~Priority_Node() {
    if (this->next != nullptr) {
        delete this->next;
    }
}