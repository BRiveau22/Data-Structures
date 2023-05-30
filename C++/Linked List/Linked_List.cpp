#include "Linked_List.h"

#pragma region Constructors
LinkedList::LinkedList()
{
	this->_head = nullptr;
	this->_size = 0;
}

LinkedList::LinkedList(int data)
{
	this->_head = new Node(data);
	this->_size = 1;
}

LinkedList::LinkedList(std::vector<int> vec)
{
	if (vec.size() != 0)
	{
		this->_head = new Node(vec[0]);
		this->_size = 1;
		Node *current_node = _head;

		for (int i = 1; i < vec.size(); i++)
		{
			Node *new_node = new Node(vec[i]);
			current_node->_next = new_node;
			current_node = new_node;
			_size++;
		}
	}
	else
	{
		this->_head = nullptr;
		this->_size = 0;
	}
}
#pragma endregion

#pragma region Destructor
LinkedList::~LinkedList()
{
	delete _head;
}
#pragma endregion

#pragma region Public Methods
void LinkedList::push_front(int data)
{
	Node *new_node = new Node(data);

	if (_size > 0)
	{
		new_node->_next = _head;
	}
	_head = new_node;
	_size++;
}

void LinkedList::push_back(int data)
{
	Node *new_node = new Node(data);

	if (_size > 0)
	{
		Node *current_node = _head;
		while (current_node->_next != nullptr)
		{
			current_node = current_node->_next;
		}
		current_node->_next = new_node;
	}
	else
	{
		_head = new_node;
	}

	_size++;
}

void LinkedList::insert(int data, int idx)
{
	if (idx >= _size)
	{
		push_back(data);
	}
	else if (idx <= 0)
	{
		push_front(data);
	}
	else
	{
		Node *new_node = new Node(data);
		Node *current_node = _head;
		for (int i = 0; i < idx - 1; i++)
		{
			current_node = current_node->_next;
		}

		new_node->_next = current_node->_next;
		current_node->_next = new_node;
		_size++;
	}
}

void LinkedList::remove(int data)
{
	bool removed = false;

	if (_size == 1 && _head->_data == data)
	{
		_head = nullptr;
		_size--;
	}
	else
	{
		Node *current_node = _head;
		Node *prev_node = nullptr;

		while (current_node->_next != nullptr && !removed)
		{
			if (current_node->_data == data && current_node == _head)
			{
				_head = current_node->_next;
				removed = true;
				_size--;
			}
			else if (current_node->_data == data)
			{
				prev_node->_next = current_node->_next;
				removed = true;
				_size--;
			}
			prev_node = current_node;
			current_node = current_node->_next;
		}
		if (current_node->_next == nullptr && current_node->_data == data)
		{
			prev_node->_next = nullptr;
		}
	}
}

bool LinkedList::contains(int data)
{
	bool is_found = false;

	if (_size == 1)
	{
		is_found = _head->_data == data;
	}
	else
	{
		Node *current_node = _head;
		while (current_node != nullptr)
		{
			if (current_node->_data == data)
			{
				is_found = true;
				break;
			}
			else
			{
				current_node = current_node->_next;
			}
		}
	}
	return is_found;
}

int LinkedList::get_size()
{
	return this->_size;
}

std::string LinkedList::to_string()
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