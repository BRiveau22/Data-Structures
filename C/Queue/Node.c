#include "Node.h"

Node* create() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = 0;
    node->next = NULL;
    return node;
}

void destroy(Node* node) {
    free(node);
}