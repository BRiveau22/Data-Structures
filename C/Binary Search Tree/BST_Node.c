#include "BST_Node.h"

// Constructor
BST_Node *create_node()
{
    BST_Node *node = (BST_Node *)malloc(sizeof(BST_Node));
    node->_data = 0;
    node->_left = NULL;
    node->_right = NULL;
    return node;
}

// Destructor
void destroy_node(BST_Node *root)
{
    if (root != NULL)
    {
        destroy_node(root->_left);
        destroy_node(root->_right);
        free(root);
    }
}