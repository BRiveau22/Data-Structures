#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

typedef struct Queue {
    Node* front;
    Node* rear;
    unsigned int size;
}Queue;

Queue* create_queue();
Queue* create_queue(int data);
Queue* create_queue(int* arr);
void destroy(Queue* queue);
void enqueue(Queue* queue, int data);
void dequeue(Queue* queue);
int peek(Queue* queue);
int get_size(Queue* queue);

#endif