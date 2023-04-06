#pragma once


// head
//  5  ->  3  ->  8  ->  6  -> X
// p1


class Priority_Node {
private:
    int data;
    Priority_Node* next;
    int priority;

    friend class Priority_Queue;
public:
    Priority_Node();
    // Overloading
    Priority_Node(int data);
    Priority_Node(int data, Priority_Node* next);
    Priority_Node(int data, int priority);
    ~Priority_Node();
};