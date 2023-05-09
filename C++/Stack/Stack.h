#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <string>
#include <vector>

class Stack{
private:
    Node* top;
    unsigned int size;

public:
    // Constructors
    Stack();
    Stack(int data);
    Stack(std::vector<int> data);

    // Destructor
    ~Stack();

    // Methods
    void push(int data);
    int pop();
    int peek();
    bool is_empty();
    unsigned int get_size();
};

#endif