#ifndef PRIORITY_NODE_H
#define PRIORITY_NODE_H
class Priority_Node
{
private:
#pragma region Private Properties
    int _data;
    Priority_Node *_next;
    int _priority;
#pragma endregion

    friend class Priority_Queue;

public:
#pragma region Constructors
    Priority_Node();
    Priority_Node(int data);
    Priority_Node(int data, Priority_Node *next);
    Priority_Node(int data, int priority);
#pragma endregion

#pragma region Destructor
    ~Priority_Node();
#pragma endregion
};

#endif