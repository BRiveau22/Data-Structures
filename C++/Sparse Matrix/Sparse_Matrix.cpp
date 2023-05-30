#include "Sparse_Matrix.h"

#pragma region Constructors
Sparse_Matrix::Sparse_Matrix()
{
	this->_rows = 0;
	this->_cols = 0;
	this->_head = nullptr;
	this->_tail = nullptr;
	this->_num_elements = 0;
}

Sparse_Matrix::Sparse_Matrix(std::vector<std::vector<int>> matrix)
{
	Node *current_node = new Node();
	this->_head = current_node;
	this->_num_elements = 0;
	this->_rows = 0;
	this->_cols = 0;

	for (int y = 0; y < matrix.size(); y++)
	{
		for (int x = 0; x < matrix[y].size(); x++)
		{
			if (matrix[y][x] != 0)
			{
				current_node->_row = y;
				current_node->_col = x;
				current_node->_val = matrix[y][x];
				this->_num_elements++;
			}

			if (y == matrix.size() - 1 && x == matrix[y].size() - 1)
			{
				this->_tail = current_node;
			}

			if (current_node->_row > this->_rows)
			{
				this->_rows = current_node->_row;
			}
			if (current_node->_col > this->_cols)
			{
				this->_cols = current_node->_col;
			}

			else
			{
				current_node->_next = new Node();
				current_node = current_node->_next;
			}
		}
	}
}
#pragma endregion

#pragma region Destructor
Sparse_Matrix::~Sparse_Matrix()
{
	delete this->_head;
	this->_head = nullptr;
	this->_tail = nullptr;
}
#pragma endregion

#pragma region Private Methods
std::pair<int, int> Sparse_Matrix::get_max_row_col(Sparse_Matrix other)
{
	int max_row = 0;
	int max_col = 0;

	if (other._rows > this->_rows)
	{
		max_row = other._rows;
	}
	else
	{
		max_row = this->_rows;
	}
	if (other._cols > this->_cols)
	{
		max_col = other._cols;
	}
	else
	{
		max_col = this->_cols;
	}

	return {max_row, max_col};
}

std::vector<std::vector<int>> Sparse_Matrix::add(Sparse_Matrix longer, Sparse_Matrix shorter, int max_row, int max_col)
{
	std::vector<std::vector<int>> new_matrix(max_row + 1, std::vector<int>(max_col + 1, 0));
	Node *current_node_first = longer._head;
	Node *current_node_second = shorter._head;

	while (current_node_first != nullptr)
	{
		new_matrix[current_node_first->_row][current_node_first->_col] += current_node_first->_val;
		current_node_first = current_node_first->_next;
	}

	while (current_node_second != nullptr)
	{
		new_matrix[current_node_second->_row][current_node_second->_col] += current_node_second->_val;
		current_node_second = current_node_second->_next;
	}

	return new_matrix;
}

std::vector<std::vector<int>> Sparse_Matrix::multiply(Sparse_Matrix first, Sparse_Matrix second)
{
	std::vector<std::vector<int>> new_matrix(first._rows, std::vector<int>(second._cols, 0));
	Node *current_node1 = first._head;
	Node *current_node2 = second._head;

	while (current_node1 != nullptr)
	{
		while (current_node2 != nullptr)
		{
			if (current_node1->_col == current_node2->_row)
			{
				new_matrix[current_node1->_row][current_node2->_col] += current_node1->_val * current_node2->_val;
			}
			current_node2 = current_node2->_next;
		}
		current_node1 = current_node1->_next;
		current_node2 = second._head;
	}

	return new_matrix;
}
#pragma endregion

#pragma region Public Methods
Sparse_Matrix Sparse_Matrix::add(Sparse_Matrix add_matrix)
{
	std::pair<int, int> extremes = this->get_max_row_col(add_matrix);
	int max_row = extremes.first;
	int max_col = extremes.second;

	// Creates a new 2D vector with the max row and column
	std::vector<std::vector<int>> new_matrix;

	// Reassigns the new matrix to the sum of the two matrices
	if (this->_num_elements >= add_matrix._num_elements)
	{
		new_matrix = this->add(*this, add_matrix, max_row, max_col);
	}
	else
	{
		new_matrix = this->add(add_matrix, *this, max_row, max_col);
	}

	// Creates a sparse matrix from the new matrix
	Sparse_Matrix out_matrix = Sparse_Matrix(new_matrix);
	return out_matrix;
}

Sparse_Matrix Sparse_Matrix::multiply(Sparse_Matrix mult_matrix)
{
	// Creates a new 2D vector with the max row and column
	std::vector<std::vector<int>> new_matrix;

	// Reassigns the new matrix to the product of the two matrices
	new_matrix = this->multiply(*this, mult_matrix);

	// Creates a sparse matrix from the new matrix
	Sparse_Matrix out_matrix = Sparse_Matrix(new_matrix);
	return out_matrix;
}

void Sparse_Matrix::insert(int row, int col, int val)
{
	Node *current_node = this->_head;

	while (current_node->_next != nullptr)
	{
		// Handles the case where the node is inserted in the middle
		if (current_node->_next->_row > row || (current_node->_next->_row == row && current_node->_next->_col > col))
		{
			current_node->_next = new Node(row, col, val, current_node->_next);
			this->_num_elements++;
		}
		// Handles the case where the node is inserted in the middle and the location is the same
		else if (current_node->_next->_row == row && current_node->_next->_col == col)
		{
			current_node->_next->_val = val;
		}
		current_node = current_node->_next;
	}

	// Handles the case where the node is inserted at the tail or the head of an otherwise empty matrix
	if (current_node->_next == nullptr && (current_node->_row <= row || (current_node->_row == row && current_node->_col < col)))
	{
		current_node->_next = new Node(row, col, val);
		this->_num_elements++;
	}
	// Handles the case where the node is inserted at the head of an otherwise empty matrix
	else if (current_node == this->_head && current_node->_next == nullptr && (current_node->_row > row || (current_node->_row == row && current_node->_col > col)))
	{
		Node *new_node = new Node(row, col, val, current_node);
		this->_head = new_node;
		this->_num_elements++;
	}
	// Handles the case where the node is inserted at the tail, or the head of an otherwise empty matrix and the location is the same
	else if (current_node->_next == nullptr && current_node->_row == row && current_node->_col == col)
	{
		current_node->_val = val;
	}
}

void Sparse_Matrix::print_matrix()
{
	Node *current_node = this->_head;

	while (current_node != nullptr)
	{
		if (current_node->_val != 0)
		{
			std::cout << current_node->_val << " ";
		}

		if (current_node->_next != nullptr && current_node->_next->_row != current_node->_row)
		{
			std::cout << "\n";
		}
		current_node = current_node->_next;
	}
}
#pragma endregion