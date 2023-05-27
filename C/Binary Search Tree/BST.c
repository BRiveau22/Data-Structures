#include "BST.h"

// Constructor
BST *create_tree()
{
    BST *tree = (BST *)malloc(sizeof(BST));
    tree->_root = NULL;
    tree->_size = 0;
    return tree;
}

// Destructor
void destroy_tree(BST *tree)
{
    destroy_node(tree->_root);
    free(tree);
}

// Methods
BST_Node *insert(BST *tree, BST_Node *root, int data)
{
    if (data == root->_data)
    {
        return root;
    }

    if (root == NULL)
    {
        tree->_size++;
        return create_node(data);
    }
    else if (data > root->_data)
    {
        root->_right = insert(tree, root->_right, data);
    }
    else if (data < root->_data)
    {
        root->_left = insert(tree, root->_left, data);
    }
}

BST_Node *find_ios(BST *tree, BST_Node *root)
{
    while (root->_left != NULL)
    {
        root = root->_left;
    }

    return root;
}

BST_Node *remove(BST *tree, BST_Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->_data == data)
    {
        // Case 1: No children
        if (root->_left == NULL && root->_right == NULL)
        {
            destroy_node(root);
            return NULL;
        }

        // Case 2: One child
        if (root->_left == NULL)
        {
            BST_Node *temp = root->_right;
            root->_right = remove(tree, root->_right, temp->_data);
            return temp;
        }
        if (root->_right == NULL)
        {
            BST_Node *temp = root->_left;
            root->_left = remove(tree, root->_left, temp->_data);
            return temp;
        }

        // Case 3: Two children
        BST_Node *ios = find_ios(tree, root->_right);
        root->_data = ios->_data;
        root->_right = remove(tree, root->_right, ios->_data);
    }
    else if (data > root->_data)
    {
        root->_right = remove(tree, root->_right, data);
    }
    else if (data < root->_data)
    {
        root->_left = remove(tree, root->_left, data);
    }

    return root;
}

bool search(BST *tree, BST_Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->_data == data)
    {
        return true;
    }
    else if (data > root->_data)
    {
        return search(tree, root->_right, data);
    }
    else if (data < root->_data)
    {
        return search(tree, root->_left, data);
    }
}

void preorder(BST *tree, BST_Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf(root->_data + " ");
    preorder(tree, root->_left);
    preorder(tree, root->_right);
}

void inorder(BST *tree, BST_Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(tree, root->_left);
    printf(root->_data + " ");
    inorder(tree, root->_right);
}

void postorder(BST *tree, BST_Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(tree, root->_left);
    postorder(tree, root->_right);
    printf(root->_data + " ");
}

int height(BST *tree, BST_Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = height(tree, root->_left);
    int right_height = height(tree, root->_right);

    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}