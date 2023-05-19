package sparse_matrix;

public class Node {
    private int row;
    private int col;
    private int value;
    Node next;

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


    // Getters
    public int getRow(){
        return this.row;
    }


    public int getCol(){
        return this.col;
    }


    public int getValue(){
        return this.value;
    }


    public Node getNext(){
        return this.next;
    }


    // Setters
    public void setRow(int row){
        this.row = row;
    }


    public void setCol(int col){
        this.col = col;
    }


    public void setValue(int value){
        this.value = value;
    }


    public void setNext(Node next){
        this.next = next;
    }
}
