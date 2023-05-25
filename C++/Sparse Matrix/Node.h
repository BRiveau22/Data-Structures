#ifndef NODE_H
#define NODE_H
class Node
{
private:
    int row;
    int col;
    int val;
    Node *next;

    friend class Sparse_Matrix;

public:
    // Constructors
    Node();
    Node(int row, int col, int val);
    Node(int row, int col, int val, Node *next);

    // Destructor
    ~Node();
};

#endif