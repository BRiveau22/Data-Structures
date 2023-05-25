#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create();
Node *create(int data);
Node *create(int data, Node *next);
void destroy(Node *node);

#endif