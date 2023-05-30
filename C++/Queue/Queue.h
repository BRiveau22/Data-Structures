#include "Node.h"
#include <vector>
#include <string>
#include <iostream>

class Queue
{
private:
#pragma region Private Properties
    Node *_head;
    Node *_tail;
    unsigned int _size;
#pragma endregion

public:
#pragma region Constructors
    Queue();
    Queue(int data);
    Queue(std::vector<int> vec);
#pragma endregion

#pragma region Destructor
    ~Queue();
#pragma endregion

#pragma region Public Methods
    void enqueue(int data);
    void dequeue();
    int peek();
    int get_size();
    std::string to_string();
#pragma endregion
};