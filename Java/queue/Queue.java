package queue;

public class Queue {
    private Node front;
    private Node back;
    private int size;

    public Queue() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    public Queue(int data) {
        this.front = new Node(data);
        this.back = this.front;
        this.size = 1;
    }

    public Queue(int[] arr) {
        this.front = new Node(arr[0]);
        this.back = this.front;
        this.size = 1;
        for (int i = 1; i < arr.length; i++) {
            this.back.setNext(new Node(arr[i]));
            this.back = this.back.getNext();
            this.size++;
        }
    }

    public void enqueue(int data) {
        Node newNode = new Node(data);
        if (this.size == 0) {
            this.front = newNode;
            this.back = newNode;
        } else {
            this.back.setNext(newNode);
            this.back = this.back.getNext();
        }
        this.size++;
    }

    public void dequeue() {
        if (this.size == 0) {
            System.out.println("Queue is empty");
        } else if (this.size == 1) {
            this.front = null;
            this.back = null;
            this.size--;
        } else {
            this.front = this.front.getNext();
            this.size--;
        }
    }

    public int peek() {
        if (this.size == 0) {
            System.out.println("Queue is empty");
            return -1;
        }

        return this.front.getData();
    }

    public int getSize() {
        return this.size;
    }
}