#ifndef PRIORITY_NODE_H
#define PRIORITY_NODE_H
class Priority_Node
{
private:
    int data;
    Priority_Node *next;
    int priority;

    friend class Priority_Queue;

public:
    // Constructors
    Priority_Node();
    Priority_Node(int data);
    Priority_Node(int data, Priority_Node *next);
    Priority_Node(int data, int priority);

    // Destructor
    ~Priority_Node();
};

#endif