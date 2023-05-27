#ifndef NODE_H
#define NODE_H
#include <stddef.h>

typedef struct Node
{
    int _data;
    struct Node *_next;
} Node;

// Constructor
Node *create_node_data(int data);

// Destructor
void destroy_node(Node *node);

#endif