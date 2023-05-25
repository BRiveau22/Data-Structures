#include "Priority_Node.h"

Priority_Node *create_node()
{
    Priority_Node *node = (Priority_Node *)malloc(sizeof(Priority_Node));
    node->priority = 0;
    node->data = 0;
    node->next = NULL;
    return node;
}

Priority_Node *create_node(int data)
{
    Priority_Node *node = (Priority_Node *)malloc(sizeof(Priority_Node));
    node->priority = 0;
    node->data = data;
    node->next = NULL;
    return node;
}

Priority_Node *create_node(int data, Priority_Node *next)
{
    Priority_Node *node = (Priority_Node *)malloc(sizeof(Priority_Node));
    node->priority = 0;
    node->data = data;
    node->next = next;
    return node;
}

Priority_Node *create_node(int data, int priority)
{
    Priority_Node *node = (Priority_Node *)malloc(sizeof(Priority_Node));
    node->priority = priority;
    node->data = data;
    node->next = NULL;
    return node;
}

void destroy(Priority_Node *node)
{
    free(node);
}