#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include "Node.h"
#include <vector>
#include <string>
#include <iostream>

class Sparse_Matrix
{
private:
#pragma region Private Properties
	int _rows;
	int _cols;
	Node *_head;
	Node *_tail;
	int _num_elements;
#pragma endregion

#pragma region Private Methods
	std::vector<std::vector<int>> add(Sparse_Matrix longer, Sparse_Matrix shorter, int max_row, int max_col);
	std::vector<std::vector<int>> multiply(Sparse_Matrix first, Sparse_Matrix second);
	std::pair<int, int> get_max_row_col(Sparse_Matrix other);
#pragma endregion

public:
#pragma region Constructors
	Sparse_Matrix();
	Sparse_Matrix(std::vector<std::vector<int>> matrix);
#pragma endregion

#pragma region Destructor
	~Sparse_Matrix();
#pragma endregion

#pragma region Public Methods
	Sparse_Matrix multiply(Sparse_Matrix mult_matrix);
	Sparse_Matrix add(Sparse_Matrix add_matrix);
	void insert(int row, int col, int val);
	void print_matrix();
#pragma endregion
};
#endif