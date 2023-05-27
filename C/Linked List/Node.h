#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stddef.h>

typedef struct Node
{
    int _data;
    struct Node *_next;
} Node;

// Constructors
Node *create_node();
Node *create_node_data(int data);
Node *create_node_full(int data, Node *next);

// Destructor
void destroy_node(Node *node);

#endif