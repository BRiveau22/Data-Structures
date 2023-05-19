package sparse_matrix;

public class SparseMatrix{
    private int rows;
    private int cols;
    private Node head;
    private int numElements;

    // Constructors
    public SparseMatrix(){
        this.rows = 0;
        this.cols = 0;
        this.head = null;
        this.numElements = 0;
    }


    public SparseMatrix(int[][] matrix){
        this.numElements = 0;

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++){
                if(matrix[i][j] != 0 && this.head == null){
                    this.head = new Node(i, j, matrix[i][j]);
                    this.numElements++;
                }
                else if (matrix[i][j] != 0){
                    Node temp = this.getTail();
                    temp.setNext(new Node(i, j, matrix[i][j]));
                    this.rows = temp.getNext().getRow() + 1;
                    this.cols = temp.getNext().getCol() + 1;
                    this.numElements++;
                }
            }
        }
    }


    // Private Methods
    private Node getTail(){
        Node temp = this.head;
        while(temp.getNext() != null){
            temp = temp.getNext();
        }

        return temp;
    }


    private int[][] add(SparseMatrix longer, SparseMatrix shorter, int maxRow, int maxCol){
        int[][] outMatrix = new int[maxRow][maxCol];
        Node temp = longer.head;

        while(temp != null){
            outMatrix[temp.getRow()][temp.getCol()] = temp.getValue();
            temp = temp.getNext();
        }

        temp = shorter.head;

        while(temp != null){
            outMatrix[temp.getRow()][temp.getCol()] += temp.getValue();
            temp = temp.getNext();
        }

        return outMatrix;
    }


    private int[][] multiply(SparseMatrix first, SparseMatrix second){
        int[][] outMatrix = new int[first.rows][second.cols];
        Node firstTemp = first.head;

        while(firstTemp != null){
            Node secondTemp = second.head;
            while(secondTemp != null){
                if(firstTemp.getCol() == secondTemp.getRow()){
                    outMatrix[firstTemp.getRow()][secondTemp.getCol()] += firstTemp.getValue() * secondTemp.getValue();
                }
                secondTemp = secondTemp.getNext();
            }
            firstTemp = firstTemp.getNext();
        }

        return outMatrix;
    }


    private int[] getMaxRowCol(SparseMatrix other){
        int[] maxRowCol = new int[2];
        maxRowCol[0] = this.rows;
        maxRowCol[1] = this.cols;

        if(other.rows > maxRowCol[0]){
            maxRowCol[0] = other.rows;
        }

        if(other.cols > maxRowCol[1]){
            maxRowCol[1] = other.cols;
        }

        return maxRowCol;
    }


    // Public Methods
    public SparseMatrix multiply(SparseMatrix multMatrix){
        int[][] outMatrix = this.multiply(this, multMatrix);
        return new SparseMatrix(outMatrix);
    }


    public SparseMatrix add(SparseMatrix addMatrix){
        int[] maxRowCol = this.getMaxRowCol(addMatrix);
        int[][] outMatrix = this.add(this, addMatrix, maxRowCol[0], maxRowCol[1]);
        return new SparseMatrix(outMatrix);
    }


    public void insert(int row, int col, int value){
        Node currentNode = this.head;

	    while (currentNode.next != null) {
	    	//Handles the case where the node is inserted in the middle
	    	if (currentNode.getNext().getRow() > row || (currentNode.getNext().getRow() == row && currentNode.next.getCol() > col)) {
	    		currentNode.next = new Node(row, col, value, currentNode.next);
	    		this.numElements++;
	    	}
	    	//Handles the case where the node is inserted in the middle and the location is the same
	    	else if (currentNode.getNext().getRow() == row && currentNode.next.getCol() == col) {
	    		currentNode.next.setValue(value);
	    	}
	    	currentNode = currentNode.next;
	    }

	    //Handles the case where the node is inserted at the tail or the head of an otherwise empty matrix
	    if (currentNode.next == null && (currentNode.getRow() <= row || (currentNode.getRow() == row && currentNode.getCol() < col))) {
	    	currentNode.next = new Node(row, col, value);
	    	this.numElements++;
	    }
	    //Handles the case where the node is inserted at the head of an otherwise empty matrix
	    else if (currentNode == this.head && currentNode.next == null && (currentNode.getRow() > row || (currentNode.getRow() == row && currentNode.getCol() > col))) {
	    	Node newNode = new Node(row, col, value, currentNode);
	    	this.head = newNode;
	    	this.numElements++;
	    }
	    //Handles the case where the node is inserted at the tail, or the head of an otherwise empty matrix and the location is the same
	    else if (currentNode.getNext() == null && currentNode.getRow() == row && currentNode.getCol() == col) {
	    	currentNode.setValue(value);
	    }
    }


    public void printMatrix(){
        Node temp = this.head;
        while(temp != null){
            System.out.println("Row: " + temp.getRow() + ", Col: " + temp.getCol() + ", Value: " + temp.getValue());
            temp = temp.next;
        }
    }
}