#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Priority_Node.h"
#include "stdbool.h"

typedef struct Priority_Queue
{
    Priority_Node *_front;
    Priority_Node *_back;
    int _size;
} Priority_Queue;

// Constructors
Priority_Queue *create_queue();
Priority_Queue *create_queue_data(int data);
Priority_Queue *create_queue_arr(int *arr);

// Destructors
void destroy_queue(Priority_Queue *queue);

// Methods
void enqueue(Priority_Queue *queue, int data, int priority);
void dequeue(Priority_Queue *queue);
int peek(Priority_Queue *queue);
int get_size(Priority_Queue *queue);
bool is_empty(Priority_Queue *queue);

#endif