#include "BST_Node.h"

BST_Node *create_node()
{
    BST_Node *node = (BST_Node *)malloc(sizeof(BST_Node));
    node->data = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void destroy(BST_Node *root)
{
    if (root != NULL)
    {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}