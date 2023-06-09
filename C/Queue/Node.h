#ifndef NODE_H
#define NODE_H
#include <stddef.h>

typedef struct Node
{
    int _data;
    struct Node *_next;
} Node;

#pragma region Constructor
Node *create_node_data(int data);
#pragma endregion

#pragma region Destructor
void destroy_node(Node *node);
#pragma endregion
#endif