#ifndef PRIORITY_NODE_H
#define PRIORITY_NODE_H
#include <stdlib.h>

typedef struct Priority_Node {
    int data;
    int priority;
    struct Priority_Node* next;
} Priority_Node;

Priority_Node* create_node();
Priority_Node* create_node(int data);
Priority_Node* create_node (int data, Priority_Node* next);
Priority_Node* create_node(int data, int priority);
void destroy(Priority_Node* node);

#endif