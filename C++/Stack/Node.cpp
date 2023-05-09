#include "Node.h"

// Constructors
Node::Node(){
    this->data = 0;
    this->next = nullptr;
}

Node::Node(int data){
    this->data = data;
    this->next = nullptr;
}

Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
}

// Destructor
Node::~Node(){
    this->next = nullptr;
}