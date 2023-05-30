#ifndef BST_H
#define BST_H
#include <iostream>

class BSTNode
{
private:
#pragma region Private Properties
	int _data;
	BSTNode *_left;
	BSTNode *_right;
#pragma endregion

	friend class BSTree;

public:
#pragma region Constructor
	BSTNode(int data);
#pragma endregion

#pragma region Destructor
	~BSTNode();
#pragma endregion
};

class BSTree
{
private:
#pragma region Private properties
	BSTNode *_root;
#pragma endregion

#pragma region Private methods
	void destroy(BSTNode *current_node);
	BSTNode *insert(BSTNode *current_node, int data);
	BSTNode *remove(BSTNode *current_node, int data);
	int height(BSTNode *root);
	void preorder(BSTNode *root, std::ostream &os);
	void inorder(BSTNode *root, std::ostream &os);
	void postorder(BSTNode *root, std::ostream &os);
	BSTNode *find_ios(BSTNode *current_node);
	BSTNode *find_iop(BSTNode *current_node);
#pragma endregion

public:
#pragma region Constructors
	BSTree();
#pragma endregion

#pragma region Destructor
	~BSTree();
#pragma endregion

#pragma region Public methods
	void insert(int data);
	int height();
	void remove(int data);
	void preorder(std::ostream &os = std::cout);
	void inorder(std::ostream &os = std::cout);
	void postorder(std::ostream &os = std::cout);
	bool search(int data);
#pragma endregion
};

#endif