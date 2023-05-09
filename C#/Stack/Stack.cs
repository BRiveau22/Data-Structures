public class Node{
    private int data;
    private Node next;

    // Constructors
    public Node(){
        this.data = 0;
        this.next = null;
    }
    public Node(int data){
        this.data = data;
        this.next = null;
    }
    public Node(int data, Node next){
        this.data = data;
        this.next = next;
    }
}

public class Stack{
    private Node top;
    private int size;

    // Constructors
    public Stack(){
        this.top = null;
        this.size = 0;
    }

    public Stack(int data){
        this.top = new Node(data);
        this.size = 1;
    }

    public Stack(int[] data){
        this.top = new Node(data[0]);
        this.size = 1;

        Node current = this.top;
        for(int i = 0; i < data.Length; i++){
            current.next = new Node(data[i]);
            current = current.next;
            this.size++;
        }
    }

    // Methods
    public void push(int data){
        Node newNode = new Node(data);
        newNode.next = this.top;
        this.top = newNode;
        this.size++;
    }

    public int pop(){
        if(!isEmpty){
            int data = this.top.data;
            this.top = this.top.next;
            this.size--;
            return data;
        }

        return -1;
    }

    public int peek(){
        if(!isEmpty){
            return this.top.data;
        }

        return -1;
    }

    public bool isEmpty(){
        return this.size == 0;
    }

    public int size(){
        return this.size;
    }
}