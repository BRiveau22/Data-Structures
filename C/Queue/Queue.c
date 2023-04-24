#include "Queue.h"

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

Queue* create_queue(int data){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = create_node(data);
    queue->rear = queue->front;
    queue->size = 1;
    return queue;
}

Queue* create_queue(int* arr) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = create_node(arr[0]);
    queue->rear = queue->front;
    queue->size = 1;
    for (int i = 1; arr[i] != '\0'; i++) {
        enqueue(queue, arr[i]);
        queue->size++;
    }
    return queue;
}

void destroy(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void enqueue(Queue* queue, int data) {
    Node* node = create_node(data);
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* node = queue->front;
    queue->front = queue->front->next;
    destroy(node);
    queue->size--;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

int get_size(Queue* queue) {
    return queue->size;
}