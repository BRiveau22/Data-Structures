#include "Stack.h"

Stack *create_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

Stack *create_stack_single(int data)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = create_node_data(data);
    stack->size = 1;
    return stack;
}

Stack *create_stack_list(int data[])
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = create_node_data(data[0]);
    stack->size = 1;

    Node *current = stack->top;
    for (int i = 1; i < sizeof(data) / sizeof(data[0]); i++)
    {
        current->next = create_node_data(data[i]);
        current = current->next;
        stack->size++;
    }
    return stack;
}

void destroy(Stack *stack)
{
    Node *current = stack->top;
    while (current != NULL)
    {
        Node *next = current->next;
        destroy(current);
        current = next;
    }
    free(stack);
}

void push(Stack *stack, int data)
{
    Node *node = create_node_data(data);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int pop(Stack *stack)
{
    if (is_empty(stack) == 0)
    {
        return -1;
    }
    Node *node = stack->top;
    int data = node->data;
    stack->top = node->next;
    destroy(node);
    stack->size--;
    return data;
}

int peek(Stack *stack)
{
    if (is_empty(stack) == 0)
    {
        return -1;
    }
    return stack->top->data;
}

int is_empty(Stack *stack)
{
    return stack->size == 0;
}

int size(Stack *stack)
{
    return stack->size;
}