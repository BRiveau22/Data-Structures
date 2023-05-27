#include "Queue.h"

// Constructors
Queue *create_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->_front = NULL;
    queue->_rear = NULL;
    queue->_size = 0;
    return queue;
}

Queue *create_queue_data(int data)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->_front = create_node_data(data);
    queue->_rear = queue->_front;
    queue->_size = 1;
    return queue;
}

Queue *create_queue_arr(int *arr)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->_front = create_node_data(arr[0]);
    queue->_rear = queue->_front;
    queue->_size = 1;
    for (int i = 1; arr[i] != '\0'; i++)
    {
        enqueue(queue, arr[i]);
        queue->_size++;
    }
    return queue;
}

// Destructor
void destroy_queue(Queue *queue)
{
    while (!is_empty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}

// Methods
void enqueue(Queue *queue, int data)
{
    Node *node = create_node_data(data);
    if (is_empty(queue))
    {
        queue->_front = node;
        queue->_rear = node;
    }
    else
    {
        queue->_rear->_next = node;
        queue->_rear = node;
    }
    queue->_size++;
}

void dequeue(Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    Node *node = queue->_front;
    queue->_front = queue->_front->_next;
    destroy_node(node);
    queue->_size--;
}

int peek(Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->_front->_data;
}

int get_size(Queue *queue)
{
    return queue->_size;
}

bool is_empty(Queue *queue)
{
    return queue->_size == 0;
}