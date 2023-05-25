#ifndef BST_H
#define BST_H
#include "BST_Node.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct BST
{
    struct BST_Node *root;
    int size;
} BST;

BST *create();
void destroy(BST_Node *root);
BST_Node *insert(BST *tree, BST_Node *root, int data);
int height(BST *tree, BST_Node *root);
BST_Node *find_ios(BST *tree, BST_Node *root); // In Order Successor (IOS)
BST_Node *remove(BST *tree, BST_Node *root, int data);
void preorder(BST *tree, BST_Node *root);
void inorder(BST *tree, BST_Node *root);
void postorder(BST *tree, BST_Node *root);
bool search(BST *tree, BST_Node *root, int data);

#endif