public class Node{
    private int row;
    private int col;
    private int value;
    private Node next;

    // Constructors
    public Node(){
        this.row = 0;
        this.col = 0;
        this.value = 0;
        this.next = null;
    }

    public Node(int row, int col, int value){
        this.row = row;
        this.col = col;
        this.value = value;
        this.next = null;
    }

    public Node(int row, int col, int value, Node next){
        this.row = row;
        this.col = col;
        this.value = value;
        this.next = next;
    }
}


public class Sparse_Matrix{
    private int rows;
    private int cols;
    private Node head;
    private int num_elements;

    // Constructors
    public Sparse_Matrix(){
        this.rows = 0;
        this.cols = 0;
        this.head = null;
        this.num_elements = 0;
    }

    public Sparse_Matrix(int[][] matrix){
        this.num_elements = 0;

        for(int i = 0; i < matrix.Length; i++){
            for(int j = 0; j < matrix[i].Length; j++){
                if(matrix[i][j] != 0 && this.head == null){
                    this.head = new Node(i, j, matrix[i][j]);
                    this.num_elements++;
                }
                else if (matrix[i][j] != 0){
                    Node temp = this.find_tail();
                    temp.next = new Node(i, j, matrix[i][j]);
                    this.rows = temp.next.row + 1;
                    this.cols = temp.next.col + 1;
                    this.num_elements++;
                }
            }
        }
    }

    // Private methods
    private Node find_tail(){
        Node temp = this.head;
        while(temp.next != null){
            temp = temp.next;
        }

        return temp;
    }


    private int[][] add(Sparse_Matrix longer, Sparse_Matrix shorter, int max_row, int max_col){
        int[][] out_matrix = new int[max_row][max_col];
        Node temp = longer.head;
        while(temp != null){
            out_matrix[temp.row][temp.col] = temp.value;
            temp = temp.next;
        }

        temp = shorter.head;
        while(temp != null){
            out_matrix[temp.row][temp.col] += temp.value;
            temp = temp.next;
        }

        return out_matrix;
    }


    private int[][] multiply(Sparse_Matrix first, Sparse_Matrix second){
        int[][] out_matrix = new int[first.rows][second.cols];
        Node first_temp = first.head;

        while(first_temp != null){
            Node second_temp = second.head;
            while(second_temp != null){
                if(first_temp.col == second_temp.row){
                    out_matrix[first_temp.row][second_temp.col] += first_temp.value * second_temp.value;
                }
                second_temp = second_temp.next;
            }
            first_temp = first_temp.next;
        }

        return out_matrix;
    }


    private int[] get_max_row_col(Sparse_Matrix other){
        int max_row = this.rows;
        int max_col = this.cols;

        if(other.rows > max_row){
            max_row = other.rows;
        }

        if(other.cols > max_col){
            max_col = other.cols;
        }

        return new int[]{max_row, max_col};
    }


    // Public methods
    public Sparse_Matrix multiply(Sparse_Matrix mult_matrix){
        int[][] out_matrix = this.multiply(this, mult_matrix);
        return new Sparse_Matrix(out_matrix);
    }


    public Sparse_Matrix add(Sparse_Matrix add_matrix){
        int[] max_row_col = this.get_max_row_col(add_matrix);
        int max_row = max_row_col[0];
        int max_col = max_row_col[1];

        int[][] out_matrix = this.add(this, add_matrix, max_row, max_col);
        return new Sparse_Matrix(out_matrix);
    }


    public void insert(int row, int col, int value){
        Node current_node = this.head;

	    while (current_node.next != nullptr) {
	    	//Handles the case where the node is inserted in the middle
	    	if (current_node.next.row > row || (current_node.next.row == row && current_node.next.col > col)) {
	    		current_node.next = new Node(row, col, value, current_node.next);
	    		this.num_elements++;
	    	}
	    	//Handles the case where the node is inserted in the middle and the location is the same
	    	else if (current_node.next.row == row && current_node.next.col == col) {
	    		current_node.next.val = value;
	    	}
	    	current_node = current_node.next;
	    }

	    //Handles the case where the node is inserted at the tail or the head of an otherwise empty matrix
	    if (current_node.next == nullptr && (current_node.row <= row || (current_node.row == row && current_node.col < col))) {
	    	current_node.next = new Node(row, col, value);
	    	this.num_elements++;
	    }
	    //Handles the case where the node is inserted at the head of an otherwise empty matrix
	    else if (current_node == this.head && current_node.next == nullptr && (current_node.row > row || (current_node.row == row && current_node.col > col))) {
	    	Node new_node = new Node(row, col, value, current_node);
	    	this.head = new_node;
	    	this.num_elements++;
	    }
	    //Handles the case where the node is inserted at the tail, or the head of an otherwise empty matrix and the location is the same
	    else if (current_node.next == nullptr && current_node.row == row && current_node.col == col) {
	    	current_node.value = value;
	    }
    }


    public void print_matrix(){
        Node temp = this.head;
        while(temp != null){
            Console.WriteLine("Row: {0}, Col: {1}, Value: {2}", temp.row, temp.col, temp.value);
            temp = temp.next;
        }
    }
}