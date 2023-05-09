#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <vector>
#include <string>
#include <iostream>

class LinkedList {
private:
    Node* head;
    unsigned int size;

public:
    // Constructors
    LinkedList();
    LinkedList(int data);
    LinkedList(std::vector<int> vec);

    // Destructor
    ~LinkedList();

    // Methods
    void push_front(int data);
    void push_back(int data);
    void insert(int data, int idx); // For any `idx` > `size`, append the value
    void remove(int data);
    bool contains(int data);
    int get_size();
    std::string to_string();
};

#endif