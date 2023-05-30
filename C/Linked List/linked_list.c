#include "Linked_List.h"

#pragma region Constructor
LinkedList *create_linked_list()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->_head = NULL;
    list->_size = 0;
    return list;
}
#pragma endregion

#pragma region Destructor
void destroy_linked_list(LinkedList *list)
{
    Node *current = list->_head;
    Node *next;
    while (current != NULL)
    {
        next = current->_next;
        destroy_node(current);
        current = next;
    }
    free(list);
}
#pragma endregion

#pragma region Methods
void append(LinkedList *list, int data)
{
    Node *new_node = create_node_data(data);
    if (list->_head == NULL)
    {
        list->_head = new_node;
    }
    else
    {
        Node *current = list->_head;
        while (current->_next != NULL)
        {
            current = current->_next;
        }
        current->_next = new_node;
    }
    list->_size++;
}

void prepend(LinkedList *list, int data)
{
    Node *new_node = create(data);
    new_node->_next = list->_head;
    list->_head = new_node;
    list->_size++;
}

void insert(LinkedList *list, int data, int idx)
{
    if (idx < 1)
    {
        prepend(list, data);
    }
    else if (idx >= list->_size)
    {
        append(list, data);
    }
    else
    {
        Node *new_node = create(data);
        Node *current = list->_head;
        for (int i = 0; i < idx - 1; i++)
        {
            current = current->_next;
        }
        new_node->_next = current->_next;
        current->_next = new_node;
        list->_size++;
    }
}

void remove(LinkedList *list, int data)
{
    Node *current = list->_head;
    while (current->_next->_data != data)
    {
        current = current->_next;
    }
    Node *temp = current->_next;
    current->_next = current->_next->_next;
    destroy_node(temp);
}

bool contains(LinkedList *list, int data)
{
    Node *current = list->_head;
    while (current != NULL)
    {
        if (current->_data == data)
        {
            return true;
        }
        current = current->_next;
    }
    return false;
}

void print(LinkedList *list)
{
    Node *current = list->_head;
    while (current != NULL)
    {
        printf(current->_data + " ");
        current = current->_next;
    }
}
#pragma endregion