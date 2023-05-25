#include "Priority_Queue.h"

Priority_Queue *create_queue()
{
    Priority_Queue *queue = (Priority_Queue *)malloc(sizeof(Priority_Queue));
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
    return queue;
}

Priority_Queue *create_queue(int data)
{
    Priority_Queue *queue = (Priority_Queue *)malloc(sizeof(Priority_Queue));
    queue->front = create_node(data, 0);
    queue->back = queue->front;
    queue->size = 1;
    return queue;
}

Priority_Queue *create_queue(int *arr)
{
    Priority_Queue *queue = (Priority_Queue *)malloc(sizeof(Priority_Queue));
    queue->front = create_node(arr[0], 0);
    queue->back = queue->front;
    queue->size = 1;
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        enqueue(queue, arr[i], 0);
    }
    return queue;
}

void destroy(Priority_Queue *queue)
{
    Priority_Node *temp = queue->front;
    while (temp != NULL)
    {
        Priority_Node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(queue);
}

void enqueue(Priority_Queue *queue, int data, int priority)
{
    Priority_Node *new_node = create_node(data, priority);
    Priority_Node *temp = queue->front;

    // Empty queue
    if (isEmpty(queue) || queue->front != NULL)
    {
        queue->front = new_node;
        queue->back = new_node;
        queue->size++;
        return;
    }

    while (temp->next != NULL && temp->next->priority <= new_node->priority)
    {
        temp = temp->next;
    }

    if (queue->front->priority > priority)
    {
        new_node->next = queue->front;
        queue->front = new_node;
    }
    else if (temp->next == NULL && temp->priority <= new_node->priority)
    {
        temp->next = new_node;
        queue->back = new_node;
    }
    else
    {
        new_node->next = temp->next;
        temp->next = new_node;
    }

    queue->size++;
}

void dequeue(Priority_Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    Priority_Node *node = queue->front;
    queue->front = queue->front->next;
    destroy(node);
    queue->size--;
}

int peek(Priority_Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

int get_size(Priority_Queue *queue)
{
    return queue->size;
}