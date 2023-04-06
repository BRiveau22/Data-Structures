#include "Queue.h"
#include <iostream>

// O(1)
Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// O(1)
Queue::Queue(int data) {
    this->head = new Node(data);
    this->tail = head;
    this->size = 1;
}

// O(n)
Queue::Queue(std::vector<int> vec) {
    if (vec.empty()) {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    else {
        this->head = new Node(vec[0]);
        this->tail = head;
        Node* temp = this->head;

        for (int i = 1; i < vec.size(); i++) {
            temp->next = new Node(vec[i]);
            temp = temp->next;
            this->tail = temp;
        }
    }
    this->size = vec.size();
}

Queue::~Queue() {
    delete this->head;
    this->head = nullptr;
    this->tail = nullptr;
}

// O(n)
// O(1) with a tail pointer
void Queue::enqueue(int data) {
    if (head == nullptr) {
        this->head = new Node(data);
        // Assign tail
        this->tail = head;
    }
    else {
        this->tail->next = new Node(data);
        this->tail = this->tail->next;
    }

    this->size++;
}

// O(n)
// O(1) if `idx` == 0
void Queue::dequeue() {
    Node* tmp = this->head;

    // We found the element
    if (this->size > 0 || tmp != nullptr) {
        // Deleting the head
        this->head = tmp->next;

        // Without this, the Node destructor will delete
        // every element in the list after 'temp'
        tmp->next = nullptr;
        delete tmp;

        this->size--;

    }
}

// O(n)
int Queue::peek() {
    if (head != nullptr) {
        return this->head->data;
    }
    else {
        return -1;
    }
}

// O(1)
int Queue::get_size() {
    return this->size;
}

// O(n)
std::string Queue::to_string() {
    std::string stringified;
    Node* tmp = this->head;

    while (tmp != nullptr) {
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}