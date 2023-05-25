#include "Priority_Queue.h"

// Constructors
Priority_Queue::Priority_Queue()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

Priority_Queue::Priority_Queue(int data)
{
    this->head = new Priority_Node(data, 0);
    this->tail = head;
    this->size = 1;
}

Priority_Queue::Priority_Queue(std::vector<int> vec)
{
    if (vec.empty())
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    else
    {
        this->head = new Priority_Node(vec[0], 0);
        this->tail = head;
        Priority_Node *temp = this->head;

        for (int i = 1; i < vec.size(); i++)
        {
            temp->next = new Priority_Node(vec[i], i);
            temp = temp->next;
            this->tail = temp;
        }
    }
    this->size = vec.size();
}

// Destructor
Priority_Queue::~Priority_Queue()
{
    delete this->head;
    this->head = nullptr;
    this->tail = nullptr;
}

// Methods
void Priority_Queue::enqueue(int data, int priority)
{
    Priority_Node *enqueue_node = new Priority_Node(data, priority);

    if (this->size == 0 || head == nullptr)
    {
        this->head = enqueue_node;
        this->tail = head;
    }
    else
    {
        Priority_Node *current_node = head;
        while (current_node->next != nullptr && current_node->next->priority <= priority)
        {
            current_node = current_node->next;
        }

        if (head->priority > priority)
        {
            enqueue_node->next = head;
            head = enqueue_node;
        }
        else if (current_node->next == nullptr && current_node->priority <= priority)
        {
            current_node->next = enqueue_node;
            tail = enqueue_node;
        }
        else
        {
            enqueue_node->next = current_node->next;
            current_node->next = enqueue_node;
        }
    }

    this->size++;
}

void Priority_Queue::dequeue()
{
    Priority_Node *tmp = this->head;

    if (this->size > 0)
    {
        this->head = tmp->next;
        tmp->next = nullptr;
        delete tmp;

        this->size--;
    }
    else
    {
        std::cout << "The queue is empty!" << std::endl;
    }
}

std::pair<int, int> Priority_Queue::peek()
{
    std::pair<int, int> out_pair = {-100, -100};
    if (size > 0)
    {
        out_pair = {head->data, head->priority};
    }
    return out_pair;
}

int Priority_Queue::get_size()
{
    return this->size;
}

std::string Priority_Queue::to_string()
{
    std::string stringified;
    Priority_Node *tmp = this->head;

    while (tmp != nullptr)
    {
        stringified += "(" + std::to_string(tmp->data) + "," + std::to_string(tmp->priority) + ") ";
        tmp = tmp->next;
    }

    return stringified;
}