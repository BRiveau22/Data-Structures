public class Node
{
    #region Properties
    private int _row;
    private int _col;
    private int _value;
    private Node _next;
    #endregion

    #region Constructors
    public Node()
    {
        this._row = 0;
        this._col = 0;
        this._value = 0;
        this._next = null;
    }

    public Node(int row, int col, int value)
    {
        this._row = row;
        this._col = col;
        this._value = value;
        this._next = null;
    }

    public Node(int row, int col, int value, Node next)
    {
        this._row = row;
        this._col = col;
        this._value = value;
        this._next = next;
    }
    #endregion
}


public class Sparse_Matrix
{
    #region Properties
    private int _rows;
    private int _cols;
    private Node _head;
    private int _num_elements;
    #endregion

    #region Constructors
    public Sparse_Matrix()
    {
        this._rows = 0;
        this._cols = 0;
        this._head = null;
        this._num_elements = 0;
    }

    public Sparse_Matrix(int[][] matrix)
    {
        this._num_elements = 0;

        for (int i = 0; i < matrix.Length; i++)
        {
            for (int j = 0; j < matrix[i].Length; j++)
            {
                if (matrix[i][j] != 0 && this._head == null)
                {
                    this._head = new Node(i, j, matrix[i][j]);
                    this._num_elements++;
                }
                else if (matrix[i][j] != 0)
                {
                    Node temp = this.find_tail();
                    temp._next = new Node(i, j, matrix[i][j]);
                    this._rows = temp.next.row + 1;
                    this._cols = temp.next.col + 1;
                    this._num_elements++;
                }
            }
        }
    }
    #endregion

    #region Private methods
    private Node find_tail()
    {
        Node temp = this._head;
        while (temp._next != null)
        {
            temp = temp._next;
        }

        return temp;
    }


    private int[][] add(Sparse_Matrix longer, Sparse_Matrix shorter, int max_row, int max_col)
    {
        int[][] out_matrix = new int[max_row][max_col];
        Node temp = longer._head;
        while (temp != null)
        {
            out_matrix[temp._row][temp._col] = temp._value;
            temp = temp._next;
        }

        temp = shorter._head;
        while (temp != null)
        {
            out_matrix[temp._row][temp._col] += temp._value;
            temp = temp._next;
        }

        return out_matrix;
    }


    private int[][] multiply(Sparse_Matrix first, Sparse_Matrix second)
    {
        int[][] out_matrix = new int[first._rows][second._cols];
        Node first_temp = first._head;

        while (first_temp != null)
        {
            Node second_temp = second._head;
            while (second_temp != null)
            {
                if (first_temp._col == second_temp._row)
                {
                    out_matrix[first_temp._row][second_temp._col] += first_temp._value * second_temp._value;
                }
                second_temp = second_temp._next;
            }
            first_temp = first_temp._next;
        }

        return out_matrix;
    }


    private int[] get_max_row_col(Sparse_Matrix other)
    {
        int max_row = this._rows;
        int max_col = this._cols;

        if (other._rows > max_row)
        {
            max_row = other._rows;
        }

        if (other._cols > max_col)
        {
            max_col = other._cols;
        }

        return new int[] { max_row, max_col };
    }
    #endregion

    #region Public methods
    public Sparse_Matrix multiply(Sparse_Matrix mult_matrix)
    {
        int[][] out_matrix = this.multiply(this, mult_matrix);
        return new Sparse_Matrix(out_matrix);
    }


    public Sparse_Matrix add(Sparse_Matrix add_matrix)
    {
        int[] max_row_col = this.get_max_row_col(add_matrix);
        int max_row = max_row_col[0];
        int max_col = max_row_col[1];

        int[][] out_matrix = this.add(this, add_matrix, max_row, max_col);
        return new Sparse_Matrix(out_matrix);
    }


    public void insert(int row, int col, int value)
    {
        Node current_node = this._head;

        while (current_node._next != nullptr)
        {
            //Handles the case where the node is inserted in the middle
            if (current_node.next.row > row || (current_node.next.row == row && current_node.next.col > col))
            {
                current_node._next = new Node(row, col, value, current_node._next);
                this._num_elements++;
            }
            //Handles the case where the node is inserted in the middle and the location is the same
            else if (current_node.next.row == row && current_node.next.col == col)
            {
                current_node.next.val = value;
            }
            current_node = current_node._next;
        }

        //Handles the case where the node is inserted at the tail or the head of an otherwise empty matrix
        if (current_node._next == nullptr && (current_node._row <= row || (current_node._row == row && current_node._col < col)))
        {
            current_node._next = new Node(row, col, value);
            this._num_elements++;
        }
        //Handles the case where the node is inserted at the head of an otherwise empty matrix
        else if (current_node == this._head && current_node._next == nullptr && (current_node._row > row || (current_node._row == row && current_node._col > col)))
        {
            Node new_node = new Node(row, col, value, current_node);
            this._head = new_node;
            this._num_elements++;
        }
        //Handles the case where the node is inserted at the tail, or the head of an otherwise empty matrix and the location is the same
        else if (current_node._next == nullptr && current_node._row == row && current_node._col == col)
        {
            current_node._value = value;
        }
    }


    public void print_matrix()
    {
        Node temp = this._head;
        while (temp != null)
        {
            Console.WriteLine("Row: {0}, Col: {1}, Value: {2}", temp._row, temp._col, temp._value);
            temp = temp._next;
        }
    }
    #endregion
}