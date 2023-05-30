#include "Sparse_Matrix.h"

#pragma region Constructors
Sparse_Matrix *create_sparse_matrix_empty()
{
    Sparse_Matrix *this = (Sparse_Matrix *)malloc(sizeof(Sparse_Matrix));
    this->_rows = 0;
    this->_cols = 0;
    this->_head = NULL;
    this->_tail = NULL;
    this->_num_elements = 0;
}

Sparse_Matrix *create_sparse_matrix_full(int **matrix)
{
    Sparse_Matrix *this = (Sparse_Matrix *)malloc(sizeof(Sparse_Matrix));
    Node *current_node = create_node();
    this->_head = current_node;
    this->_num_elements = 0;
    this->_rows = 0;
    this->_cols = 0;

    for (int y = 0; y < sizeof(matrix); y++)
    {
        for (int x = 0; x < sizeof(matrix[y]); x++)
        {
            if (matrix[y][x] != 0)
            {
                current_node->_row = y;
                current_node->_col = x;
                current_node->_val = matrix[y][x];
                this->_num_elements++;
            }

            if (y == sizeof(matrix) - 1 && x == sizeof(matrix[y]) - 1)
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
                current_node->_next = create_node();
                current_node = current_node->_next;
            }
        }
    }
}
#pragma endregion

#pragma region Destructor
void destroy_sparse_matrix(Sparse_Matrix *this)
{
    free(this->_head);
    this->_head = NULL;
    this->_tail = NULL;
}
#pragma endregion

#pragma region Private Methods
int **create_array(int rows, int cols)
{
    int *values = calloc(rows * cols, sizeof(int));
    int **array = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        array[i] = values + i * cols;
    }
    return array;
}

int *get_max_row_col(Sparse_Matrix *this, Sparse_Matrix *other)
{
    int max_row = 0;
    int max_col = 0;

    if (other->_rows > this->_rows)
    {
        max_row = other->_rows;
    }
    else
    {
        max_row = this->_rows;
    }
    if (other->_cols > this->_cols)
    {
        max_col = other->_cols;
    }
    else
    {
        max_col = this->_cols;
    }

    return (int[]){max_row, max_col};
}

int **_add(Sparse_Matrix *longer, Sparse_Matrix *shorter, int max_row, int max_col)
{
    int **new_matrix = create_array(max_row + 1, max_col + 1);
    Node *current_node_first = longer->_head;
    Node *current_node_second = shorter->_head;

    while (current_node_first != NULL)
    {
        new_matrix[current_node_first->_row][current_node_first->_col] += current_node_first->_val;
        current_node_first = current_node_first->_next;
    }

    while (current_node_second != NULL)
    {
        new_matrix[current_node_second->_row][current_node_second->_col] += current_node_second->_val;
        current_node_second = current_node_second->_next;
    }

    return new_matrix;
}

int **_multiply(Sparse_Matrix *first, Sparse_Matrix *second)
{
    int **new_matrix = create_array(first->_rows, second->_cols);
    Node *current_node1 = first->_head;
    Node *current_node2 = second->_head;

    while (current_node1 != NULL)
    {
        while (current_node2 != NULL)
        {
            if (current_node1->_col == current_node2->_row)
            {
                new_matrix[current_node1->_row][current_node2->_col] += current_node1->_val * current_node2->_val;
            }
            current_node2 = current_node2->_next;
        }
        current_node1 = current_node1->_next;
        current_node2 = second->_head;
    }

    return new_matrix;
}
#pragma endregion

#pragma region Public Methods
Sparse_Matrix *add(Sparse_Matrix *this, Sparse_Matrix *add_matrix)
{
    int *extremes = get_max_row_col(this, add_matrix);
    int max_row = extremes[0];
    int max_col = extremes[1];

    // Creates a new 2D vector with the max row and column
    int **new_matrix;

    // Reassigns the new matrix to the sum of the two matrices
    if (this->_num_elements >= add_matrix->_num_elements)
    {
        new_matrix = _add(this, add_matrix, max_row, max_col);
    }
    else
    {
        new_matrix = _add(add_matrix, this, max_row, max_col);
    }

    // Creates a sparse matrix from the new matrix
    Sparse_Matrix *out_matrix = create_sparse_matrix_full(new_matrix);
    return out_matrix;
}

Sparse_Matrix *multiply(Sparse_Matrix *this, Sparse_Matrix *mult_matrix)
{
    // Creates a new 2D vector with the max row and column
    int **new_matrix;

    // Reassigns the new matrix to the product of the two matrices
    new_matrix = _multiply(this, mult_matrix);

    // Creates a sparse matrix from the new matrix
    Sparse_Matrix *out_matrix = create_sparse_matrix_full(new_matrix);
    return out_matrix;
}

void insert(Sparse_Matrix *this, int row, int col, int val)
{
    Node *current_node = this->_head;

    while (current_node->_next != NULL)
    {
        // Handles the case where the node is inserted in the middle
        if (current_node->_next->_row > row || (current_node->_next->_row == row && current_node->_next->_col > col))
        {
            current_node->_next = create_node_full(row, col, val, current_node->_next);
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
    if (current_node->_next == NULL && (current_node->_row <= row || (current_node->_row == row && current_node->_col < col)))
    {
        current_node->_next = create_node_data(row, col, val);
        this->_num_elements++;
    }
    // Handles the case where the node is inserted at the head of an otherwise empty matrix
    else if (current_node == this->_head && current_node->_next == NULL && (current_node->_row > row || (current_node->_row == row && current_node->_col > col)))
    {
        Node *new_node = create_node_full(row, col, val, current_node);
        this->_head = new_node;
        this->_num_elements++;
    }
    // Handles the case where the node is inserted at the tail, or the head of an otherwise empty matrix and the location is the same
    else if (current_node->_next == NULL && current_node->_row == row && current_node->_col == col)
    {
        current_node->_val = val;
    }
}

void print_matrix(Sparse_Matrix *this)
{
    Node *current_node = this->_head;

    while (current_node != NULL)
    {
        if (current_node->_val != 0)
        {
            fwrite(current_node->_val + " ");
        }

        if (current_node->_next != NULL && current_node->_next->_row != current_node->_row)
        {
            fwrite("\n");
        }
        current_node = current_node->_next;
    }
}
#pragma endregion