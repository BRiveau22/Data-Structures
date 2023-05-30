#include "Node.h"

#pragma region Constructors
Node *create_node_data()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->_data = 0;
    node->_next = NULL;
    return node;
}
#pragma endregion

#pragma region Destructors
void destroy_node(Node *node)
{
    free(node);
}
#pragma endregion