#include "Node.h"

#pragma region Constructors
Node::Node()
{
    this->_row = 0;
    this->_col = 0;
    this->_val = 0;
    this->_next = nullptr;
}

Node::Node(int row, int col, int val)
{
    this->_row = row;
    this->_col = col;
    this->_val = val;
    this->_next = nullptr;
}

Node::Node(int row, int col, int val, Node *next)
{
    this->_row = row;
    this->_col = col;
    this->_val = val;
    this->_next = next;
}
#pragma endregion

#pragma region Destructor
Node::~Node()
{
    if (this->_next != nullptr)
    {
        delete this->_next;
    }
}
#pragma endregion