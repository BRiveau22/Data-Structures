#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Priority_Node.h"
#include <vector>
#include <string>
#include <iostream>

class Priority_Queue {
private:
    Priority_Node* head;
    Priority_Node* tail;
    unsigned int size;

public:
    // Constructors
    Priority_Queue();
    Priority_Queue(int data);
    Priority_Queue(std::vector<int> vec);

    // Destructor
    ~Priority_Queue();

    // Methods
    void enqueue(int data, int priority); 
    void dequeue(); 
    std::pair<int, int> peek();
    int get_size();
    std::string to_string();
};

#endif