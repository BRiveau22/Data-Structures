#include "Node.h"

#pragma region Constructors
Node *create_node()
{
    Node *this = (Node *)malloc(sizeof(Node));
    this->_row = 0;
    this->_col = 0;
    this->_val = 0;
    this->_next = NULL;
}

Node *create_node_data(int row, int col, int val)
{
    Node *this = (Node *)malloc(sizeof(Node));
    this->_row = row;
    this->_col = col;
    this->_val = val;
    this->_next = NULL;
}

Node *create_node_full(int row, int col, int val, Node *next)
{
    Node *this = (Node *)malloc(sizeof(Node));
    this->_row = row;
    this->_col = col;
    this->_val = val;
    this->_next = next;
}
#pragma endregion

#pragma region Destructor
void destroy_node(Node *this)
{
    if (this->_next != NULL)
    {
        free(this->_next);
    }
}
#pragma endregion