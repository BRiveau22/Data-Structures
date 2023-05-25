#include "Node.h"

Node *create_node()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = 0;
    node->next = NULL;
    return node;
}

Node *create_node_data(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node *create_node_next(int data, Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

void destroy(Node *node)
{
    free(node);
}