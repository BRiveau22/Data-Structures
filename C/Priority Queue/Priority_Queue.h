#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Priority_Node.h"

typedef struct Priority_Queue{
    Priority_Node* front;
    Priority_Node* back;
    int size;
}Priority_Queue;

Priority_Queue* create_queue();
Priority_Queue* create_queue(int data);
Priority_Queue* create_queue(int* arr);
void destroy(Priority_Queue* queue);
void enqueue(Priority_Queue* queue, int data, int priority);
void dequeue(Priority_Queue* queue);
int peek(Priority_Queue* queue);
int get_size(Priority_Queue* queue);

#endif