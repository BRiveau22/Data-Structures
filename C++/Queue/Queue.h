#include "Node.h"
#include <vector>
#include <string>
#include <iostream>

class Queue
{
private:
    Node *head;
    Node *tail;
    unsigned int size;

public:
    // Constructors
    Queue();
    Queue(int data);
    Queue(std::vector<int> vec);

    // Destructor
    ~Queue();

    // Methods
    void enqueue(int data);
    void dequeue();
    int peek();
    int get_size();
    std::string to_string();
};