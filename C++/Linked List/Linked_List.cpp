#include "Linked_List.h"

// Constructors
LinkedList::LinkedList()
{
	this->head = nullptr;
	this->size = 0;
}

LinkedList::LinkedList(int data)
{
	this->head = new Node(data);
	this->size = 1;
}

LinkedList::LinkedList(std::vector<int> vec)
{
	if (vec.size() != 0)
	{
		this->head = new Node(vec[0]);
		this->size = 1;
		Node *current_node = head;

		for (int i = 1; i < vec.size(); i++)
		{
			Node *new_node = new Node(vec[i]);
			current_node->next = new_node;
			current_node = new_node;
			size++;
		}
	}
	else
	{
		this->head = nullptr;
		this->size = 0;
	}
}

// Destructor
LinkedList::~LinkedList()
{
	delete head;
}

// Methods
void LinkedList::push_front(int data)
{
	Node *new_node = new Node(data);

	if (size > 0)
	{
		new_node->next = head;
	}
	head = new_node;
	size++;
}

void LinkedList::push_back(int data)
{
	Node *new_node = new Node(data);

	if (size > 0)
	{
		Node *current_node = head;
		while (current_node->next != nullptr)
		{
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
	else
	{
		head = new_node;
	}

	size++;
}

void LinkedList::insert(int data, int idx)
{
	if (idx >= size)
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
		Node *current_node = head;
		for (int i = 0; i < idx - 1; i++)
		{
			current_node = current_node->next;
		}

		new_node->next = current_node->next;
		current_node->next = new_node;
		size++;
	}
}

void LinkedList::remove(int data)
{
	bool removed = false;

	if (size == 1 && head->data == data)
	{
		head = nullptr;
		size--;
	}
	else
	{
		Node *current_node = head;
		Node *prev_node = nullptr;

		while (current_node->next != nullptr && !removed)
		{
			if (current_node->data == data && current_node == head)
			{
				head = current_node->next;
				removed = true;
				size--;
			}
			else if (current_node->data == data)
			{
				prev_node->next = current_node->next;
				removed = true;
				size--;
			}
			prev_node = current_node;
			current_node = current_node->next;
		}
		if (current_node->next == nullptr && current_node->data == data)
		{
			prev_node->next = nullptr;
		}
	}
}

bool LinkedList::contains(int data)
{
	bool is_found = false;

	if (size == 1)
	{
		is_found = head->data == data;
	}
	else
	{
		Node *current_node = head;
		while (current_node != nullptr)
		{
			if (current_node->data == data)
			{
				is_found = true;
				break;
			}
			else
			{
				current_node = current_node->next;
			}
		}
	}
	return is_found;
}

int LinkedList::get_size()
{
	return this->size;
}

std::string LinkedList::to_string()
{
	std::string stringified;
	Node *tmp = this->head;

	while (tmp != nullptr)
	{
		stringified += std::to_string(tmp->data) + " ";
		tmp = tmp->next;
	}

	return stringified;
}