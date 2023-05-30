#include "Node.h"

#pragma region Constructors
Node *create_node()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->_data = 0;
    node->_next = NULL;
    return node;
}

Node *create_node_data(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->_data = data;
    node->_next = NULL;
    return node;
}

Node *create_node_next(int data, Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->_data = data;
    node->_next = next;
    return node;
}
#pragma endregion

#pragma region Destructor
void destroy_node(Node *node)
{
    free(node);
}
#pragma endregion