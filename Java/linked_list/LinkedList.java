package linked_list;

public class LinkedList {
    private Node head;
    private int size;

    public LinkedList() {
        this.head = null;
        this.size = 0;
    }

    public LinkedList(int data) {
        this.head = new Node(data);
        this.size = 1;
    }

    public LinkedList (int[] list){
        this.head = new Node(list[0]);
        this.size = 1;
        for (int i = 1; i < list.length; i++) {
            this.append(list[i]);
            this.size++;
        }
    }

    public Node getHead() {
        return this.head;
    }

    public int getSize() {
        return this.size;
    }

    public void prepend(int data) {
        Node newNode = new Node(data);
        newNode.setNext(this.head);
        this.head = newNode;
        this.size++;
    }

    public void append(int data){
        Node newNode = new Node(data);
        Node current = this.head;
        while (current.getNext() != null) {
            current = current.getNext();
        }
        current.setNext(newNode);
        this.size++;
    }

    public void insert(int data, int idx){
        if (idx < 1) {
            this.prepend(data);
        }
        else if (idx >= this.size){
            this.append(data);
        }
        else {
            Node newNode = new Node(data);
            Node current = this.head;
            for (int i = 0; i < idx - 1; i++) {
                current = current.getNext();
            }
            newNode.setNext(current.getNext());
            current.setNext(newNode);
            this.size++;
        }
    }

    public void remove(int data){
        Node current = this.head;
        if (current.getData() == data) {
            this.head = current.getNext();
            this.size--;
        }
        else {
            while (current.getNext() != null) {
                if (current.getNext().getData() == data) {
                    current.setNext(current.getNext().getNext());
                    this.size--;
                    break;
                }
                current = current.getNext();
            }
        }
    }

    public boolean contains(int data){
        Node current = this.head;
        while (current != null) {
            if (current.getData() == data) {
                return true;
            }
            current = current.getNext();
        }
        return false;
    }

    public void printList(){
        Node current = this.head;
        while (current != null) {
            System.out.print(current.getData() + " ");
            current = current.getNext();
        }
        System.out.println();
    }
}
