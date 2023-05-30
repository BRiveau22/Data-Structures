#ifndef NODE_H
#define NODE_H
#include <stddef.h>

typedef struct Node
{
#pragma region Private Properties
    int _row;
    int _col;
    int _val;
    Node *_next;
#pragma endregion
} Node;

#pragma region Constructors
Node *create_node();
Node *create_node_data(int row, int col, int val);
Node *create_node_full(int row, int col, int val, Node *next);
#pragma endregion

#pragma region Destructor
void destroy_node(Node *this);
#pragma endregion

#endif