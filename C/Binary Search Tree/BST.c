#include "BST.h"

BST* create(){
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void destroy(BST* tree){
    destroy(tree->root);
    free(tree);
}

BST_Node* insert(BST* tree, BST_Node* root, int data){
    if(data == root->data) {
        return root;
    }

    if(root == NULL){
        tree->size++;
        return create_node(data);
    } 
    else if(data > root->data){
        root->right = insert(tree, root->right, data);
    } 
    else if(data < root->data){
        root->left = insert(tree, root->left, data);
    }
}

BST_Node* find_ios(BST* tree, BST_Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

BST_Node* remove(BST* tree, BST_Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if(root->data == data) {
        // Case 1: No children
        if(root->left == NULL && root->right == NULL) {
            destroy(root);
            return NULL;
        }

        // Case 2: One child
        if(root->left == NULL) {
            BST_Node* temp = root->right;
            root->right = remove(tree, root->right, temp->data);
            return temp;
        }
        if(root->right == NULL) {
            BST_Node* temp = root->left;
            root->left = remove(tree, root->left, temp->data);
            return temp;
        }

        // Case 3: Two children
        BST_Node* ios = find_ios(tree, root->right);
        root->data = ios->data;
        root->right = remove(tree, root->right, ios->data);
    }
    else if (data > root->data) {
        root->right = remove(tree, root->right, data);
    }
    else if (data < root->data) {
        root->left = remove(tree, root->left, data);
    }

    return root;
}

bool search(BST* tree, BST_Node* root, int data) {
    if(root == NULL) {
        return false;
    }

    if(root->data == data) {
        return true;
    }
    else if(data > root->data) {
        return search(tree, root->right, data);
    }
    else if(data < root->data) {
        return search(tree, root->left, data);
    }
}

void preorder(BST* tree, BST_Node* root) {
    if(root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(tree, root->left);
    preorder(tree, root->right);
}

void inorder(BST* tree, BST_Node* root){
    if(root == NULL) {
        return;
    }

    inorder(tree, root->left);
    printf("%d ", root->data);
    inorder(tree, root->right);
}

void postorder(BST* tree, BST_Node* root) {
    if(root == NULL) {
        return;
    }

    postorder(tree, root->left);
    postorder(tree, root->right);
    printf("%d ", root->data);
}

int height(BST* tree, BST_Node* root) {
    if(root == NULL) {
        return 0;
    }

    int left_height = height(tree, root->left);
    int right_height = height(tree, root->right);

    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}