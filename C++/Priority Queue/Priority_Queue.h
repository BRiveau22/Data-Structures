#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Priority_Node.h"
#include <vector>
#include <string>
#include <iostream>

class Priority_Queue
{
private:
#pragma region Private Properties
    Priority_Node *_head;
    Priority_Node *_tail;
    unsigned int _size;
#pragma endregion

public:
#pragma region Constructors
    Priority_Queue();
    Priority_Queue(int data);
    Priority_Queue(std::vector<int> vec);
#pragma endregion

#pragma region Destructor
    ~Priority_Queue();
#pragma endregion

#pragma region Public Methods
    void enqueue(int data, int priority);
    void dequeue();
    std::pair<int, int> peek();
    int get_size();
    std::string to_string();
#pragma endregion
};

#endif