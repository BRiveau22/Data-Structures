package stack;

public class Node {
    private int data;
    private Node next;

    // Constructors
    public Node() {
        this.data = 0;
        this.next = null;
    }

    public Node(int data) {
        this.data = data;
        this.next = null;
    }

    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

    // Getters
    public int getData() {
        return this.data;
    }

    public Node getNext() {
        return this.next;
    }

    // Setters
    public void setData(int data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
