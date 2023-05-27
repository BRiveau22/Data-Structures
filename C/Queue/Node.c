#include "Node.h"

Node *create_node_data()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->_data = 0;
    node->_next = NULL;
    return node;
}

void destroy_node(Node *node)
{
    free(node);
}