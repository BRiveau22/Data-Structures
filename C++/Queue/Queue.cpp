#include "Queue.h"

// Constructors
Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}


Queue::Queue(int data) {
    this->head = new Node(data);
    this->tail = head;
    this->size = 1;
}


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


// Destructor
Queue::~Queue() {
    delete this->head;
    this->head = nullptr;
    this->tail = nullptr;
}


// Methods
void Queue::enqueue(int data) {
    if (head == nullptr) {
        this->head = new Node(data);
        this->tail = head;
    }
    else {
        this->tail->next = new Node(data);
        this->tail = this->tail->next;
    }

    this->size++;
}


void Queue::dequeue() {
    Node* tmp = this->head;

    if (this->size > 0 || tmp != nullptr) {
        this->head = tmp->next;
        tmp->next = nullptr;
        delete tmp;

        this->size--;
    }
}


int Queue::peek() {
    if (head != nullptr) {
        return this->head->data;
    }
    else {
        return -1;
    }
}


int Queue::get_size() {
    return this->size;
}


std::string Queue::to_string() {
    std::string stringified;
    Node* tmp = this->head;

    while (tmp != nullptr) {
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}