#include "Linked_List.h"

LinkedList* create(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void destroy(LinkedList* list){
    Node* current = list->head;
    Node* next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void append(LinkedList* list, int data){
    Node* new_node = create(int data);
    if(list->head == NULL){
        list->head = new_node;
    } else {
        Node* current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

void prepend(LinkedList* list, int data){
    Node* new_node = create(int data);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void insert(LinkedList* list, int data, int idx){
    if(idx < 1){
        prepend(list, data);
    } else if(idx >= list->size){
        append(list, data);
    } else {
        Node* new_node = create(int data);
        Node* current = list->head;
        for(int i = 0; i < idx - 1; i++){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        list->size++;
    }
}

void remove(LinkedList* list, int data){
    Node* current = list->head;
    while(current->next->data != data){
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

bool contains(LinkedList* list, int data) {
    Node* current = list->head;
    while(current != NULL){
        if(current->data == data){
            return true;
        }
        current = current->next;
    }
    return false;
}

void print(LinkedList* list) {
    Node* current = list->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}