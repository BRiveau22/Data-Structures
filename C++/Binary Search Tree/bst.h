#include <iostream>

class BSTNode {
private:
	int data;
	BSTNode* left;
	BSTNode* right;

	friend class BSTree;
public:
	BSTNode(int data);
	~BSTNode();
};

class BSTree {
private:
	BSTNode* root;
	void destroy(BSTNode* current_node);
	BSTNode* insert(BSTNode* current_node, int data);
	BSTNode* remove(BSTNode* current_node, int data);
	int height(BSTNode* root);
	void preorder(BSTNode* root, std::ostream& os);
	void inorder(BSTNode* root, std::ostream& os);
	void postorder(BSTNode* root, std::ostream& os);
	BSTNode* find_ios(BSTNode* current_node);
	BSTNode* find_iop(BSTNode* current_node);
public:
	BSTree();
	~BSTree();
	void insert(int data);
	int height();
	void remove(int data);
	void preorder(std::ostream& os = std::cout);
	void inorder(std::ostream& os = std::cout);
	void postorder(std::ostream& os = std::cout);
	bool search(int data);
};