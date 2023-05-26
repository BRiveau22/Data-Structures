class Node {
    // Constructors
    constructor() {
        this._row = 0;
        this._col = 0;
        this._value = 0;
        this._next = null;
    }

    constructor(row, col, value) {
        this._row = row;
        this._col = col;
        this._value = value;
        this._next = null;
    }

    constructor(row, col, value, next) {
        this._row = row;
        this._col = col;
        this._value = value;
        this._next = next;
    }
}

class SparseMatrix {
    // Constructors
    constructor() {
        this._rows = 0;
        this._cols = 0;
        this._head = null;
        this._numElements = 0;
    }

    constructor(matrix) {
        this._numElements = 0;

        for (let i = 0; i < matrix.length; i++) {
            for (let j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] != 0 && this._head == null) {
                    this._head = new Node(i, j, matrix[i][j]);
                    this._numElements++;
                }
                else if (matrix[i][j] != 0) {
                    let temp = this.find_tail();
                    temp._next = new Node(i, j, matrix[i][j]);
                    this._rows = temp._next._row + 1;
                    this._cols = temp._next._col + 1;
                    this._numElements++;
                }
            }
        }
    }

    // Private Methods
    _findTail() {
        let temp = this._head;
        while (temp._next != null) {
            temp = temp._next;
        }

        return temp;
    }

    _add(longerMatrix, shorterMatrix, maxRow, maxCol) {
        const outMatrix = new int[maxRow][maxCol];
        let temp = longerMatrix._head;
        while (temp != null) {
            outMatrix[temp._row][temp._col] = temp._value;
            temp = temp.next;
        }

        temp = shorterMatrix._head;
        while (temp != null) {
            outMatrix[temp._row][temp._col] += temp._value;
            temp = temp._next;
        }

        return outMatrix;
    }


    _multiply(firstMatrix, secondMatrix) {
        const outMatrix = new int[firstMatrix._rows][secondMatrix._cols];
        let firstTemp = firstMatrix._head;

        while (firstTemp != null) {
            let secondTemp = secondMatrix._head;
            while (secondTemp != null) {
                if (firstTemp._col == secondTemp._row) {
                    outMatrix[firstTemp._row][secondTemp._col] += firstTemp._value * secondTemp._value;
                }
                secondTemp = secondTemp._next;
            }
            firstTemp = firstTemp._next;
        }

        return outMatrix;
    }


    _getMaxRowCol(otherMatrix) {
        let maxRow = this._rows;
        let maxCol = this._cols;

        if (otherMatrix._rows > maxRow) {
            maxRow = otherMatrix._rows;
        }

        if (otherMatrix._cols > maxCol) {
            maxCol = other._cols;
        }

        return { maxRow, maxCol };
    }


    // Public methods
    multiply(multMatrix) {
        const outMatrix = this._multiply(this, multMatrix);
        return new SparseMatrix(outMatrix);
    }


    add(addMatrix) {
        const maxRowCol = this.getMaxRowCol(addMatrix);
        const maxRow = maxRowCol[0];
        const maxCol = maxRowCol[1];

        const outMatrix = this._add(this, addMatrix, maxRow, maxCol);
        return new SparseMatrix(outMatrix);
    }


    insert(row, col, value) {
        let currentNode = this._head;

        while (currentNode._next != null) {
            //Handles the case where the node is inserted in the middle
            if (currentNode._next._row > row || (currentNode._next._row == row && currentNode._next._col > col)) {
                currentNode._next = new Node(row, col, value, currentNode._next);
                this._numElements++;
            }
            //Handles the case where the node is inserted in the middle and the location is the same
            else if (currentNode._next._row == row && currentNode._next._col == col) {
                currentNode._next._value = value;
            }
            currentNode = currentNode._next;
        }

        //Handles the case where the node is inserted at the tail or the head of an otherwise empty matrix
        if (currentNode._next == null && (currentNode._row <= row || (currentNode._row == row && currentNode._col < col))) {
            currentNode._next = new Node(row, col, value);
            this._numElements++;
        }
        //Handles the case where the node is inserted at the head of an otherwise empty matrix
        else if (currentNode == this._head && currentNode._next == null && (currentNode._row > row || (currentNode._row == row && currentNode._col > col))) {
            const newNode = new Node(row, col, value, currentNode);
            this.head = newNode;
            this.num_elements++;
        }
        //Handles the case where the node is inserted at the tail, or the head of an otherwise empty matrix and the location is the same
        else if (currentNode._next == null && currentNode._row == row && currentNode._col == col) {
            currentNode._value = value;
        }
    }


    printMatrix() {
        let temp = this._head;
        while (temp != null) {
            Console.log("Row: " + temp._row + ", Col: " + temp._col + ", Value: " + temp.value + "\n");
            temp = temp._next;
        }
    }
}