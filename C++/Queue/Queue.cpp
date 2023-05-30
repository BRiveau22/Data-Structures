#include "Queue.h"

#pragma region Constructors
Queue::Queue()
{
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
}

Queue::Queue(int data)
{
    this->_head = new Node(data);
    this->_tail = _head;
    this->_size = 1;
}

Queue::Queue(std::vector<int> vec)
{
    if (vec.empty())
    {
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_size = 0;
    }
    else
    {
        this->_head = new Node(vec[0]);
        this->_tail = _head;
        Node *temp = this->_head;

        for (int i = 1; i < vec.size(); i++)
        {
            temp->_next = new Node(vec[i]);
            temp = temp->_next;
            this->_tail = temp;
        }
    }
    this->_size = vec.size();
}
#pragma endregion

#pragma region Destructor
Queue::~Queue()
{
    delete this->_head;
    this->_head = nullptr;
    this->_tail = nullptr;
}
#pragma endregion

#pragma region Public Methods
void Queue::enqueue(int data)
{
    if (_head == nullptr)
    {
        this->_head = new Node(data);
        this->_tail = _head;
    }
    else
    {
        this->_tail->_next = new Node(data);
        this->_tail = this->_tail->_next;
    }

    this->_size++;
}

void Queue::dequeue()
{
    Node *tmp = this->_head;

    if (this->_size > 0 || tmp != nullptr)
    {
        this->_head = tmp->_next;
        tmp->_next = nullptr;
        delete tmp;

        this->_size--;
    }
}

int Queue::peek()
{
    if (_head != nullptr)
    {
        return this->_head->_data;
    }
    else
    {
        return -1;
    }
}

int Queue::get_size()
{
    return this->_size;
}

std::string Queue::to_string()
{
    std::string stringified;
    Node *tmp = this->_head;

    while (tmp != nullptr)
    {
        stringified += std::to_string(tmp->_data) + " ";
        tmp = tmp->_next;
    }

    return stringified;
}
#pragma endregion