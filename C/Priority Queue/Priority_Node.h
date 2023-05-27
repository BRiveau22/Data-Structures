#ifndef PRIORITY_NODE_H
#define PRIORITY_NODE_H
#include <stddef.h>

typedef struct Priority_Node
{
    int _data;
    int _priority;
    struct Priority_Node *_next;
} Priority_Node;

// Constructors
Priority_Node *create_node();
Priority_Node *create_node_data(int data);
Priority_Node *create_node_next(int data, Priority_Node *next);
Priority_Node *create_node_priority(int data, int priority);

// Destructor
void destroy_node(Priority_Node *node);

#endif