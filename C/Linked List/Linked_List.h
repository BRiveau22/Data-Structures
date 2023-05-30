#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <stdbool.h>

typedef struct LinkedList
{
    Node *_head;
    int _size;
} LinkedList;

#pragma region Constructor
LinkedList *create_linked_list();
#pragma endregion

#pragma region Destructor
void destroy_linked_list(LinkedList *list);
#pragma endregion

#pragma region Methods
void append(LinkedList *list, int data);
void prepend(LinkedList *list, int data);
void insert(LinkedList *list, int data, int index);
void remove(LinkedList *list, int data);
bool contains(LinkedList *list, int data);
void print(LinkedList *list);
#pragma endregion
#endif