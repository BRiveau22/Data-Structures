#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int data;
    Node *next;

    friend class Stack;

public:
    // Constructors
    Node();
    Node(int data);
    Node(int data, Node *next);

    // Destructor
    ~Node();
};

#endif