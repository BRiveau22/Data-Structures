#include "Node.h"
#include <vector>
#include <string>

class Queue {
private:
    Node* head;
    Node* tail;
    unsigned int size;

public:
    Queue(); // this->head = nullptr;
    Queue(int data);
    Queue(std::vector<int> vec);
    ~Queue();

    //void push_front(int data); 
    void enqueue(int data); //Rename to enqueue
    //void insert(int data, int idx);
    void dequeue(); //Modify to only remove the first element
    int peek(); //Modify to only check the first element
    int get_size();
    std::string to_string();
};