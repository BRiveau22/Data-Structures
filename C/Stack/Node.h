#ifndef NODE_H
#define NODE_H
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_node();
Node *create_node_data(int data);
Node *create_node_next(int data, Node *next);
void destroy_node(Node *node);

#endif