#include "Priority_Node.h"
#include <vector>
#include <string>

class Priority_Queue {
private:
    Priority_Node* head;
    Priority_Node* tail;
    unsigned int size;

public:
    Priority_Queue(); // this->head = nullptr;
    Priority_Queue(int data);
    Priority_Queue(std::vector<int> vec);
    ~Priority_Queue();

    void enqueue(int data, int priority); //Rename to enqueue
    void dequeue(); //Modify to only remove the first element
    std::pair<int, int> peek(); //Modify to only check the first element
    int get_size();
    std::string to_string();
};