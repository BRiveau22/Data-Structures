// Linked_List.h
#include "Node.h"
#include <stdbool.h>

typedef struct LinkedList
{
    Node *head;
    int size;
} LinkedList;

LinkedList *create();
void destroy(LinkedList *list);
void append(LinkedList *list, int data);
void prepend(LinkedList *list, int data);
void insert(LinkedList *list, int data, int index);
void remove(LinkedList *list, int data);
bool contains(LinkedList *list, int data);
void print(LinkedList *list);