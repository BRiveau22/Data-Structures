#include "Stack.h"

// Constructors
Stack::Stack()
{
    this->top = nullptr;
    this->size = 0;
}

Stack::Stack(int data)
{
    this->top = new Node(data);
    this->size = 1;
}

Stack::Stack(std::vector<int> data)
{
    this->top = new Node(data[0]);
    this->size = 1;

    Node *current = this->top;
    for (int i = 1; i < data.size(); i++)
    {
        current->next = new Node(data[i]);
        current = current->next;
    }
}

// Destructor
Stack::~Stack()
{
    Node *current = this->top;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

// Methods
void Stack::push(int data)
{
    Node *new_node = new Node(data);
    new_node->next = this->top;
    this->top = new_node;
    this->size++;
}

int Stack::pop()
{
    if (this->is_empty())
    {
        return -1;
    }

    Node *popped = this->top;
    this->top = this->top->next;
    int data = popped->data;
    delete popped;
    this->size--;
    return data;
}

int Stack::peek()
{
    if (this->is_empty())
    {
        return -1;
    }

    return this->top->data;
}

bool Stack::is_empty()
{
    return this->size == 0;
}

unsigned int Stack::get_size()
{
    return this->size;
}