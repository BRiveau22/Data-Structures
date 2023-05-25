#include "bst.h"

// Node Constructors
BSTNode::BSTNode(int data)
{
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

// Node Destructor
BSTNode::~BSTNode()
{
}

// Tree Constructors
BSTree::BSTree()
{
	this->root = nullptr;
}

// Tree Destructor
BSTree::~BSTree()
{
	destroy(this->root);
}

// Private Methods
void BSTree::destroy(BSTNode *current_node)
{
	if (current_node == nullptr)
	{
		return;
	}

	destroy(current_node->left);
	destroy(current_node->right);
	delete current_node;
}

BSTNode *BSTree::insert(BSTNode *current_node, int data)
{
	if (current_node == nullptr)
	{
		return new BSTNode(data);
	}

	if (data < current_node->data)
	{
		current_node->left = this->insert(current_node->left, data);
	}
	else
	{
		current_node->right = this->insert(current_node->right, data);
	}
	return current_node;
}

int BSTree::height(BSTNode *current_node)
{
	if (current_node == nullptr)
	{
		return 0;
	}

	int left_height = this->height(current_node->left);
	int right_height = this->height(current_node->right);

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
	if (current_node->left == nullptr)
	{
		return current_node;
	}

	return this->find_ios(current_node->left);
}

BSTNode *BSTree::remove(BSTNode *current_node, int data)
{
	if (current_node == nullptr)
	{
		return current_node;
	}

	if (current_node->data == data)
	{
		// 2 children
		if (current_node->right != nullptr && current_node->left != nullptr)
		{
			BSTNode *ios_node = find_ios(current_node);
			current_node->data = ios_node->data;
			current_node->right = this->remove(current_node->right, ios_node->data);
		}
		// 1 child (right)
		else if (current_node->right != nullptr)
		{
			current_node = current_node->right;
		}
		// 1 child (left)
		else if (current_node->left != nullptr)
		{
			current_node = current_node->left;
		}
		// No children
		else
		{
			this->destroy(current_node);
			return nullptr;
		}
	}
	else if (data < current_node->data)
	{
		current_node->left = this->remove(current_node->left, data);
	}
	else
	{
		current_node->right = this->remove(current_node->right, data);
	}

	return current_node;
}

void BSTree::preorder(BSTNode *current_node, std::ostream &os)
{
	if (current_node == nullptr)
	{
		return;
	}
	os << current_node->data << " ";
	this->preorder(current_node->left, os);
	this->preorder(current_node->right, os);
}

void BSTree::inorder(BSTNode *current_node, std::ostream &os)
{
	if (current_node == nullptr)
	{
		return;
	}
	this->inorder(current_node->left, os);
	os << current_node->data << " ";
	this->inorder(current_node->right, os);
}

void BSTree::postorder(BSTNode *current_node, std::ostream &os)
{
	if (current_node == nullptr)
	{
		return;
	}
	this->postorder(current_node->left, os);
	this->postorder(current_node->right, os);
	os << current_node->data << " ";
}

// Public Methods
void BSTree::insert(int data)
{
	if (!this->search(data))
	{
		this->root = this->insert(this->root, data);
	}
}

int BSTree::height()
{
	if (this->root == nullptr)
	{
		return -1;
	}

	return this->height(this->root);
}

void BSTree::remove(int data)
{
	if (this->search(data))
	{
		this->root = this->remove(this->root, data);
	}
}

void BSTree::preorder(std::ostream &os)
{
	this->preorder(this->root, os);
	os << "\n";
}

void BSTree::inorder(std::ostream &os)
{
	this->inorder(this->root, os);
	os << "\n";
}

void BSTree::postorder(std::ostream &os)
{
	this->postorder(this->root, os);
	os << "\n";
}

bool BSTree::search(int data)
{
	BSTNode *current_node = this->root;
	while (current_node != nullptr)
	{
		if (current_node->data == data)
		{
			return true;
		}
		else if (data < current_node->data)
		{
			current_node = current_node->left;
		}
		else
		{
			current_node = current_node->right;
		}
	}
	return false;
}