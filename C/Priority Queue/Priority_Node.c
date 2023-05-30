#include "Priority_Node.h"

#pragma region Constructors
Priority_Node *create_node()
{
    Priority_Node *node = (Priority_Node *)malloc(sizeof(Priority_Node));
    node->_priority = 0;
    node->_data = 0;
    node->_next = NULL;
    return node;
}

Priority_Node *create_node_data(int data)
{
    Priority_Node *node = (Priority_Node *)malloc(sizeof(Priority_Node));
    node->_priority = 0;
    node->_data = data;
    node->_next = NULL;
    return node;
}

Priority_Node *create_node_next(int data, Priority_Node *next)
{
    Priority_Node *node = (Priority_Node *)malloc(sizeof(Priority_Node));
    node->_priority = 0;
    node->_data = data;
    node->_next = next;
    return node;
}

Priority_Node *create_node_priority(int data, int priority)
{
    Priority_Node *node = (Priority_Node *)malloc(sizeof(Priority_Node));
    node->_priority = priority;
    node->_data = data;
    node->_next = NULL;
    return node;
}
#pragma endregion

#pragma region Destructor
void destroy_node(Priority_Node *node)
{
    free(node);
}
#pragma endregion