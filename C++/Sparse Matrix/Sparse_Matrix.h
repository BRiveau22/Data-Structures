#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include "Node.h"
#include <vector>
#include <string>
#include <iostream>

class Sparse_Matrix
{
private:
	int rows;
	int cols;
	Node *head;
	Node *tail;
	int num_elements;

	// Private Methods
	std::vector<std::vector<int>> add(Sparse_Matrix longer, Sparse_Matrix shorter, int max_row, int max_col);
	std::vector<std::vector<int>> multiply(Sparse_Matrix first, Sparse_Matrix second);
	std::pair<int, int> get_max_row_col(Sparse_Matrix other);

public:
	// Constructors
	Sparse_Matrix();
	Sparse_Matrix(std::vector<std::vector<int>> matrix);

	// Destructor
	~Sparse_Matrix();

	// Public Methods
	Sparse_Matrix multiply(Sparse_Matrix mult_matrix);
	Sparse_Matrix add(Sparse_Matrix add_matrix);
	void insert(int row, int col, int val);
	void print_matrix();
};
#endif