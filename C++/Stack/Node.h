#ifndef NODE_H
#define NODE_H

class Node
{
private:
#pragma region Private Properties
    int _data;
    Node *_next;
#pragma endregion

    friend class Stack;

public:
#pragma region Constructors
    Node();
    Node(int data);
    Node(int data, Node *next);
#pragma endregion

#pragma region Destructor
    ~Node();
#pragma endregion
};

#endif