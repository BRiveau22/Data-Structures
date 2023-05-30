#include "bst.h"

#pragma region Node Constructor
BSTNode::BSTNode(int data)
{
	this->_data = data;
	this->_left = nullptr;
	this->_right = nullptr;
}
#pragma endregion

#pragma region Node Destructor
BSTNode::~BSTNode()
{
}
#pragma endregion

#pragma region Tree Constructor
BSTree::BSTree()
{
	this->_root = nullptr;
}
#pragma endregion

#pragma region Tree Destructor
BSTree::~BSTree()
{
	destroy(this->_root);
}
#pragma endregion

#pragma region Private Methods
void BSTree::destroy(BSTNode *current_node)
{
	if (current_node == nullptr)
	{
		return;
	}

	destroy(current_node->_left);
	destroy(current_node->_right);
	delete current_node;
}

BSTNode *BSTree::insert(BSTNode *current_node, int data)
{
	if (current_node == nullptr)
	{
		return new BSTNode(data);
	}

	if (data < current_node->_data)
	{
		current_node->_left = this->insert(current_node->_left, data);
	}
	else
	{
		current_node->_right = this->insert(current_node->_right, data);
	}
	return current_node;
}

int BSTree::height(BSTNode *current_node)
{
	if (current_node == nullptr)
	{
		return 0;
	}

	int left_height = this->height(current_node->_left);
	int right_height = this->height(current_node->_right);

	if (left_height > right_height)
	{
		return left_height + 1;
	}
	else
	{
		return right_height + 1;
	}
}

BSTNode *BSTree::find_ios(BSTNode *current_node)
{
	if (current_node->_left == nullptr)
	{
		return current_node;
	}

	return this->find_ios(current_node->_left);
}

BSTNode *BSTree::remove(BSTNode *current_node, int data)
{
	if (current_node == nullptr)
	{
		return current_node;
	}

	if (current_node->_data == data)
	{
		// 2 children
		if (current_node->_right != nullptr && current_node->_left != nullptr)
		{
			BSTNode *ios_node = find_ios(current_node);
			current_node->_data = ios_node->_data;
			current_node->_right = this->remove(current_node->_right, ios_node->_data);
		}
		// 1 child (right)
		else if (current_node->_right != nullptr)
		{
			current_node = current_node->_right;
		}
		// 1 child (left)
		else if (current_node->_left != nullptr)
		{
			current_node = current_node->_left;
		}
		// No children
		else
		{
			this->destroy(current_node);
			return nullptr;
		}
	}
	else if (data < current_node->_data)
	{
		current_node->_left = this->remove(current_node->_left, data);
	}
	else
	{
		current_node->_right = this->remove(current_node->_right, data);
	}

	return current_node;
}

void BSTree::preorder(BSTNode *current_node, std::ostream &os)
{
	if (current_node == nullptr)
	{
		return;
	}
	os << current_node->_data << " ";
	this->preorder(current_node->_left, os);
	this->preorder(current_node->_right, os);
}

void BSTree::inorder(BSTNode *current_node, std::ostream &os)
{
	if (current_node == nullptr)
	{
		return;
	}
	this->inorder(current_node->_left, os);
	os << current_node->_data << " ";
	this->inorder(current_node->_right, os);
}

void BSTree::postorder(BSTNode *current_node, std::ostream &os)
{
	if (current_node == nullptr)
	{
		return;
	}
	this->postorder(current_node->_left, os);
	this->postorder(current_node->_right, os);
	os << current_node->_data << " ";
}
#pragma endregion

#pragma region Public Methods
void BSTree::insert(int data)
{
	if (!this->search(data))
	{
		this->_root = this->insert(this->_root, data);
	}
}

int BSTree::height()
{
	if (this->_root == nullptr)
	{
		return -1;
	}

	return this->height(this->_root);
}

void BSTree::remove(int data)
{
	if (this->search(data))
	{
		this->_root = this->remove(this->_root, data);
	}
}

void BSTree::preorder(std::ostream &os)
{
	this->preorder(this->_root, os);
	os << "\n";
}

void BSTree::inorder(std::ostream &os)
{
	this->inorder(this->_root, os);
	os << "\n";
}

void BSTree::postorder(std::ostream &os)
{
	this->postorder(this->_root, os);
	os << "\n";
}

bool BSTree::search(int data)
{
	BSTNode *current_node = this->_root;
	while (current_node != nullptr)
	{
		if (current_node->_data == data)
		{
			return true;
		}
		else if (data < current_node->_data)
		{
			current_node = current_node->_left;
		}
		else
		{
			current_node = current_node->_right;
		}
	}
	return false;
}
#pragma endregion