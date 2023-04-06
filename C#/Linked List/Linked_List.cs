public class Node{
    private int data;
    private Node next;

    // Constructors
    public Node() {
        this.data = 0;
        this-ndext = null;
    }

    public Node(int data){
        this.data = data;
        this.next = null;
    }

    public Node (int data, Node next){
        this.data = data;
        this.next = next;
    }
}

public class Linked_List{
    private Node head;
    private int size;

    // Constructors
    public Linked_List(){
        this.head = null;
        this.size = 0;
    }

    public Linked_List(int data){
        this.head = new Node(data);
        this.size = 1;
    }

    public Linked_List(int[] data){
        this.head = new Node(data[0]);
        this.size = 1;
        Node current = this.head;
        for (int i = 1; i < data.Length; i++){
            current.next = new Node(data[i]);
            current = current.next;
            this.size++;
        }
    }

    // Methods
    public void push_front(int data) {
        this.head = new Node(data, this.head);
    }

    public void push_back(int data) {
        Node current = this.head;
        while (current.next != null){
            current = current.next;
        }
        current.next = new Node(data);
    }

    public void insert(int data, int idx) {
        if (idx <= 0) {
            this.push_front(data);
        }
        else if (idx >= this.size) {
            this.push_back(data);
        }
        else{
            Node current = this.head;
            for (int i = 0; i < idx - 1; i++){
                current = current.next;
            }
            current.next = new Node(data, current.next);
        }
    }

    public void remove(int data) {
        Node current = this.head;
        while(current.next != null) {
            if(current.next.data == data){
                current.next = current.next.next;
                return;
            }
            current = current.next;
        }
    }

    public bool contains(int data) {
        Node current = this.head;
        while(current.next != null) {
            if(current.data == data){
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public void print() {
        Node current = this.head;
        while(current != null) {
            Console.Write(current.data + " ");
            current = current.next;
        }
        Console.WriteLine();
    }
}