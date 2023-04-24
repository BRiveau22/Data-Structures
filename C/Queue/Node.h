#ifndef NODE_H
#define NODE_H
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* create_node(int data);
void destroy(Node* node);

#endif