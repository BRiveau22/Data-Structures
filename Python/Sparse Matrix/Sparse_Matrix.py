class Node:
    # Constructors
    def __init__(self):
        self._row = 0
        self._col = 0
        self._value = 0
        self._next = None

    def __init__(self, row, col, value):
        self._row = row
        self._col = col
        self._value = value
        self._next = None

    def __init__(self, row, col, value, next_node):
        self._row = row
        self._col = col
        self._value = value
        self._next = next_node


class SparseMatrix:
    # Constructors
    def __init__(self):
        self._head = None
        self._tail = None
        self._rows = 0
        self._cols = 0
        self._num_elements = 0

    def __init__(self, matrix):
        current_node = Node()
        self._head = current_node
        self._num_elements = 0
        self._rows = 0
        self._cols = 0

        for y in range(matrix.size()):
            for x in range(matrix[y].size()):
                if matrix[y][x] != 0:
                    current_node._row = y
                    current_node._col = x
                    current_node._val = matrix[y][x]
                    self._num_elements += 1

                if y == matrix.size() - 1 and x == matrix[y].size() - 1:
                    self._tail = current_node
                if current_node._row > self._rows:
                    self._rows = current_node._row
                if current_node._col > self._cols:
                    self._cols = current_node._col
                else:
                    current_node._next = Node()
                    current_node = current_node._next

    # Private Methods
    def get_max_row_col(self, other):
        max_row = 0
        max_col = 0

        if other._rows > self._rows:
            max_row = other._rows
        else:
            max_row = self._rows

        if other._cols > self._cols:
            max_col = other._cols
        else:
            max_col = self._cols

        return {max_row, max_col}

    def _add(longer, shorter, max_row, max_col):
        new_matrix = [[None for y in range(max_row + 1)] for x in range(max_col + 1)]
        current_node_first = longer._head
        current_node_second = shorter._head

        while current_node_first != None:
            new_matrix[current_node_first._row][
                current_node_first._col
            ] += current_node_first._value
            current_node_first = current_node_first._next

        while current_node_second != None:
            new_matrix[current_node_second._row][
                current_node_second._col
            ] += current_node_second._val
            current_node_second = current_node_second._next

        return new_matrix

    def _multiply(first, second):
        new_matrix = [[None for y in range(first._rows)] for x in range(second._cols)]
        current_node1 = first._head
        current_node2 = second._head

        while current_node1 != None:
            while current_node2 != None:
                if current_node1._col == current_node2._row:
                    new_matrix[current_node1._row][current_node2._col] += (
                        current_node1._val * current_node2._val
                    )
                current_node2 = current_node2._next
            current_node1 = current_node1._next
            current_node2 = second._head

        return new_matrix

    # Public Methods
    def add(self, add_matrix):
        extremes = self.get_max_row_col(self, add_matrix)
        max_row = extremes[0]
        max_col = extremes[1]

        # Reassigns the new matrix to the sum of the two matrices
        if self._num_elements >= add_matrix._num_elements:
            new_matrix = self._add(self, add_matrix, max_row, max_col)
        else:
            new_matrix = self._add(add_matrix, self, max_row, max_col)

        # Creates a sparse matrix from the new matrix
        return SparseMatrix(new_matrix)

    def multiply(self, mult_matrix):
        # Reassigns the new matrix to the product of the two matrices
        new_matrix = self._multiply(self, mult_matrix)

        # Creates a sparse matrix from the new matrix
        out_matrix = SparseMatrix(new_matrix)
        return out_matrix

    def insert(self, row, col, val):
        current_node = self._head

        while current_node._next != None:
            # Handles the case where the node is inserted in the middle
            if current_node._next._row > row or (
                current_node._next._row == row and current_node._next._col > col
            ):
                current_node._next = Node(row, col, val, current_node._next)
                self._num_elements += 1
            # Handles the case where the node is inserted in the middle and the location is the same
            elif current_node._next._row == row and current_node._next._col == col:
                current_node._next._val = val

            current_node = current_node._next

        # Handles the case where the node is inserted at the tail or the head of an otherwise empty matrix
        if current_node._next == None and (
            current_node._row <= row
            or (current_node._row == row and current_node._col < col)
        ):
            current_node._next = Node(row, col, val)
            self._num_elements += 1
        # Handles the case where the node is inserted at the head of an otherwise empty matrix
        elif (
            current_node == self._head
            and current_node._next == None
            and (
                current_node._row > row
                or (current_node._row == row and current_node._col > col)
            )
        ):
            new_node = Node(row, col, val, current_node)
            self._head = new_node
            self._num_elements += 1
        # Handles the case where the node is inserted at the tail, or the head of an otherwise empty matrix and the location is the same
        elif (
            current_node._next == None
            and current_node._row == row
            and current_node._col == col
        ):
            current_node._value = val

    def print_matrix(self):
        current_node = self._head

        while current_node != None:
            if current_node._val != 0:
                print(current_node._val + " ")

            if (
                current_node._next != None
                and current_node._next._row != current_node._row
            ):
                print("\n")
            current_node = current_node._next
