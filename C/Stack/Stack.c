#include "Stack.h"

#pragma region Constructors
Stack *create_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->_top = NULL;
    stack->_size = 0;
    return stack;
}

Stack *create_stack_single(int data)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->_top = create_node_data(data);
    stack->_size = 1;
    return stack;
}

Stack *create_stack_list(int data[])
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->_top = create_node_data(data[0]);
    stack->_size = 1;

    Node *current = stack->_top;
    for (int i = 1; i < sizeof(data) / sizeof(data[0]); i++)
    {
        current->_next = create_node_data(data[i]);
        current = current->_next;
        stack->_size++;
    }
    return stack;
}
#pragma endregion

#pragma region Destructor
void destroy(Stack *stack)
{
    Node *current = stack->_top;
    while (current != NULL)
    {
        Node *next = current->_next;
        destroy_node(current);
        current = next;
    }
    free(stack);
}
#pragma endregion

#pragma region Methods
void push(Stack *stack, int data)
{
    Node *node = create_node_data(data);
    node->_next = stack->_top;
    stack->_top = node;
    stack->_size++;
}

int pop(Stack *stack)
{
    if (is_empty(stack) == 0)
    {
        return -1;
    }
    Node *node = stack->_top;
    int data = node->_data;
    stack->_top = node->_next;
    destroy_node(node);
    stack->_size--;
    return data;
}

int peek(Stack *stack)
{
    if (is_empty(stack) == 0)
    {
        return -1;
    }
    return stack->_top->_data;
}

int is_empty(Stack *stack)
{
    return stack->_size == 0;
}

int size(Stack *stack)
{
    return stack->_size;
}
#pragma endregion