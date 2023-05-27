#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include "stdbool.h"

typedef struct Queue
{
    Node *_front;
    Node *_rear;
    unsigned int _size;
} Queue;

// Constructors
Queue *create_queue();
Queue *create_queue_data(int data);
Queue *create_queue_arr(int *arr);

// Destructor
void destroy_queue(Queue *queue);

// Methods
void enqueue(Queue *queue, int data);
void dequeue(Queue *queue);
int peek(Queue *queue);
int get_size(Queue *queue);
bool is_empty(Queue *queue);

#endif