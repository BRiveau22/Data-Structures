#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <string>
#include <vector>

class Stack
{
private:
#pragma region Private Properties
    Node *_top;
    unsigned int _size;
#pragma endregion

public:
#pragma region Constructors
    Stack();
    Stack(int data);
    Stack(std::vector<int> data);
#pragma endregion

#pragma region Destructor
    ~Stack();
#pragma endregion

#pragma region Public Methods
    void push(int data);
    int pop();
    int peek();
    bool is_empty();
    unsigned int get_size();
#pragma endregion
};

#endif