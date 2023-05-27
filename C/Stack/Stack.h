#ifndef STACK_H
#define STACK_H
#include "Node.h"

typedef struct Stack
{
    Node *_top;
    int _size;
} Stack;

// Constructors
Stack *create_stack();
Stack *create_stack_single(int data);
Stack *create_stack_list(int data[]);

// Destructor
void destroy_stack(Stack *stack);

// Methods
void push(Stack *stack, int data);
int pop(Stack *stack);
int peek(Stack *stack);
int is_empty(Stack *stack);
int size(Stack *stack);

#endif