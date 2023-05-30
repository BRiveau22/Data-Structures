#ifndef BST_NODE_H
#define BST_NODE_H
#include <stddef.h>

typedef struct BST_Node
{
    int _data;
    struct BST_Node *_left;
    struct BST_Node *_right;
} BST_Node;

#pragma region Constructor
BST_Node *create_node(int data);
#pragma endregion

#pragma region Destructor
void destroy_node(BST_Node *root);
#pragma endregion
#endif