#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create();
Node* create(int data);
Node* create(int data, Node* next);
void destroy(Node* node);

#endif