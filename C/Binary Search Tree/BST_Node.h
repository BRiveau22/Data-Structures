#ifndef BST_NODE_H
#define BST_NODE_H
#include <stdlib.h>

typedef struct BST_Node{
    int data;
    struct BST_Node *left;
    struct BST_Node *right;
}BST_Node;

BST_Node* create_node(int data);
void destroy(BST_Node* root);

#endif