package binary_search_tree;

public class BSTNode{
    private int data;
    private BSTNode left;
    private BSTNode right;

    // Constructors
    public BSTNode(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }

    // Getters
    public BSTNode getNodeLeft(){
        return this.left;
    }

    public BSTNode getNodeRight(){
        return this.right;
    }

    public int getData(){
        return this.data;
    }

    // Setters
    public void setNodeLeft(BSTNode left){
        this.left = left;
    }

    public void setNodeRight(BSTNode right){
        this.right = right;
    }

    public void setData(int data){
        this.data = data;
    }
}