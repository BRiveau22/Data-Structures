#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include "Node.h"

typedef struct Sparse_Matrix
{
#pragma region Private Properties
    int _rows;
    int _cols;
    Node *_head;
    Node *_tail;
    int _num_elements;
#pragma endregion
} Sparse_Matrix;

#pragma region Private Methods
int **_add(Sparse_Matrix *longer, Sparse_Matrix *shorter, int max_row, int max_col);
int **_multiply(Sparse_Matrix *first, Sparse_Matrix *second);
int *get_max_row_col(Sparse_Matrix *this, Sparse_Matrix *other);
#pragma endregion

#pragma region Constructors
Sparse_Matrix *create_sparse_matrix_empty();
Sparse_Matrix *create_sparse_matrix_full(int **matrix);
#pragma endregion

#pragma region Destructor
void destroy_sparse_matrix(Sparse_Matrix *this);
#pragma endregion

#pragma region Public Methods
Sparse_Matrix *multiply(Sparse_Matrix *this, Sparse_Matrix *mult_matrix);
Sparse_Matrix *add(Sparse_Matrix *this, Sparse_Matrix *add_matrix);
void insert(Sparse_Matrix *this, int row, int col, int val);
void print_matrix(Sparse_Matrix *this);
#pragma endregion

#endif