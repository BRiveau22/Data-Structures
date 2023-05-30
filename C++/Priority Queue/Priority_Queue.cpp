#include "Priority_Queue.h"

#pragma region Constructors
Priority_Queue::Priority_Queue()
{
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
}

Priority_Queue::Priority_Queue(int data)
{
    this->_head = new Priority_Node(data, 0);
    this->_tail = _head;
    this->_size = 1;
}

Priority_Queue::Priority_Queue(std::vector<int> vec)
{
    if (vec.empty())
    {
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_size = 0;
    }
    else
    {
        this->_head = new Priority_Node(vec[0], 0);
        this->_tail = _head;
        Priority_Node *temp = this->_head;

        for (int i = 1; i < vec.size(); i++)
        {
            temp->_next = new Priority_Node(vec[i], i);
            temp = temp->_next;
            this->_tail = temp;
        }
    }
    this->_size = vec.size();
}
#pragma endregion

#pragma region Destructor
Priority_Queue::~Priority_Queue()
{
    delete this->_head;
    this->_head = nullptr;
    this->_tail = nullptr;
}
#pragma endregion

#pragma region Public Methods
void Priority_Queue::enqueue(int data, int priority)
{
    Priority_Node *enqueue_node = new Priority_Node(data, priority);

    if (this->_size == 0 || _head == nullptr)
    {
        this->_head = enqueue_node;
        this->_tail = _head;
    }
    else
    {
        Priority_Node *current_node = _head;
        while (current_node->_next != nullptr && current_node->_next->_priority <= priority)
        {
            current_node = current_node->_next;
        }

        if (_head->_priority > priority)
        {
            enqueue_node->_next = _head;
            _head = enqueue_node;
        }
        else if (current_node->_next == nullptr && current_node->_priority <= priority)
        {
            current_node->_next = enqueue_node;
            _tail = enqueue_node;
        }
        else
        {
            enqueue_node->_next = current_node->_next;
            current_node->_next = enqueue_node;
        }
    }

    this->_size++;
}

void Priority_Queue::dequeue()
{
    Priority_Node *tmp = this->_head;

    if (this->_size > 0)
    {
        this->_head = tmp->_next;
        tmp->_next = nullptr;
        delete tmp;

        this->_size--;
    }
    else
    {
        std::cout << "The queue is empty!" << std::endl;
    }
}

std::pair<int, int> Priority_Queue::peek()
{
    std::pair<int, int> out_pair = {-100, -100};
    if (_size > 0)
    {
        out_pair = {_head->_data, _head->_priority};
    }
    return out_pair;
}

int Priority_Queue::get_size()
{
    return this->_size;
}

std::string Priority_Queue::to_string()
{
    std::string stringified;
    Priority_Node *tmp = this->_head;

    while (tmp != nullptr)
    {
        stringified += "(" + std::to_string(tmp->_data) + "," + std::to_string(tmp->_priority) + ") ";
        tmp = tmp->_next;
    }

    return stringified;
}
#pragma endregion