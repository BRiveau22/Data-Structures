#include "Priority_Node.h"

#pragma region Constructors
Priority_Node::Priority_Node()
{
    this->_data = 0;
    this->_next = nullptr;
    this->_priority = 0;
}

Priority_Node::Priority_Node(int data)
{
    this->_data = data;
    this->_next = nullptr;
    this->_priority = 0;
}

Priority_Node::Priority_Node(int data, Priority_Node *next)
{
    this->_data = data;
    this->_next = next;
    this->_priority = 0;
}

Priority_Node::Priority_Node(int data, int priority)
{
    this->_data = data;
    this->_next = nullptr;
    this->_priority = priority;
}
#pragma endregion

#pragma region Destructor
Priority_Node::~Priority_Node()
{
    if (this->_next != nullptr)
    {
        delete this->_next;
    }
}
#pragma endregion