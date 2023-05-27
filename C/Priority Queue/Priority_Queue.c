#include "Priority_Queue.h"

// Constructors
Priority_Queue *create_queue()
{
    Priority_Queue *queue = (Priority_Queue *)malloc(sizeof(Priority_Queue));
    queue->_front = NULL;
    queue->_back = NULL;
    queue->_size = 0;
    return queue;
}

Priority_Queue *create_queue_data(int data)
{
    Priority_Queue *queue = (Priority_Queue *)malloc(sizeof(Priority_Queue));
    queue->_front = create_node_priority(data, 0);
    queue->_back = queue->_front;
    queue->_size = 1;
    return queue;
}

Priority_Queue *create_queue_arr(int *arr)
{
    Priority_Queue *queue = (Priority_Queue *)malloc(sizeof(Priority_Queue));
    queue->_front = create_node_priority(arr[0], 0);
    queue->_back = queue->_front;
    queue->_size = 1;
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        enqueue(queue, arr[i], 0);
    }
    return queue;
}

// Destructor
void destroy_queue(Priority_Queue *queue)
{
    Priority_Node *temp = queue->_front;
    while (temp != NULL)
    {
        Priority_Node *next = temp->_next;
        destroy_node(temp);
        temp = next;
    }
    free(queue);
}

// Methods
void enqueue(Priority_Queue *queue, int data, int priority)
{
    Priority_Node *new_node = create_node_priority(data, priority);
    Priority_Node *temp = queue->_front;

    // Empty queue
    if (is_empty(queue) || queue->_front != NULL)
    {
        queue->_front = new_node;
        queue->_back = new_node;
        queue->_size++;
        return;
    }

    while (temp->_next != NULL && temp->_next->_priority <= new_node->_priority)
    {
        temp = temp->_next;
    }

    if (queue->_front->_priority > priority)
    {
        new_node->_next = queue->_front;
        queue->_front = new_node;
    }
    else if (temp->_next == NULL && temp->_priority <= new_node->_priority)
    {
        temp->_next = new_node;
        queue->_back = new_node;
    }
    else
    {
        new_node->_next = temp->_next;
        temp->_next = new_node;
    }

    queue->_size++;
}

void dequeue(Priority_Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    Priority_Node *node = queue->_front;
    queue->_front = queue->_front->_next;
    destroy_node(node);
    queue->_size--;
}

int peek(Priority_Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->_front->_data;
}

int get_size(Priority_Queue *queue)
{
    return queue->_size;
}

bool is_empty(Priority_Queue *queue)
{
    return queue->_size == 0;
}