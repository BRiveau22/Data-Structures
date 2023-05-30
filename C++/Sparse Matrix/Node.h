#ifndef NODE_H
#define NODE_H
class Node
{
private:
#pragma region Private Properties
    int _row;
    int _col;
    int _val;
    Node *_next;
#pragma endregion

    friend class Sparse_Matrix;

public:
#pragma region Constructors
    Node();
    Node(int row, int col, int val);
    Node(int row, int col, int val, Node *next);
#pragma endregion

#pragma region Destructor
    ~Node();
#pragma endregion
};

#endif