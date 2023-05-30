#include "Stack.h"

#pragma region Constructors
Stack::Stack()
{
    this->_top = nullptr;
    this->_size = 0;
}

Stack::Stack(int data)
{
    this->_top = new Node(data);
    this->_size = 1;
}

Stack::Stack(std::vector<int> data)
{
    this->_top = new Node(data[0]);
    this->_size = 1;

    Node *current = this->_top;
    for (int i = 1; i < data.size(); i++)
    {
        current->_next = new Node(data[i]);
        current = current->_next;
    }
}
#pragma endregion

#pragma region Destructor
Stack::~Stack()
{
    Node *current = this->_top;
    while (current != nullptr)
    {
        Node *next = current->_next;
        delete current;
        current = next;
    }
}
#pragma endregion

#pragma region Public Methods
void Stack::push(int data)
{
    Node *new_node = new Node(data);
    new_node->_next = this->_top;
    this->_top = new_node;
    this->_size++;
}

int Stack::pop()
{
    if (this->is_empty())
    {
        return -1;
    }

    Node *popped = this->_top;
    this->_top = this->_top->_next;
    int data = popped->_data;
    delete popped;
    this->_size--;
    return data;
}

int Stack::peek()
{
    if (this->is_empty())
    {
        return -1;
    }

    return this->_top->_data;
}

bool Stack::is_empty()
{
    return this->_size == 0;
}

unsigned int Stack::get_size()
{
    return this->_size;
}
#pragma endregion