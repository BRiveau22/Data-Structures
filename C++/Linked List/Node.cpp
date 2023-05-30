#include "Node.h"

#pragma region Constructors
Node::Node()
{
    this->_data = 0;
    this->_next = nullptr;
}

Node::Node(int data)
{
    this->_data = data;
    this->_next = nullptr;
}

Node::Node(int data, Node *next)
{
    this->_data = data;
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