package priority_queue;

public class PriorityNode {
    int data;
    int priority;
    PriorityNode next;

    // Constructors
    public PriorityNode() {
        this.data = 0;
        this.priority = 0;
        this.next = null;
    }

    public PriorityNode(int data) {
        this.data = data;
        this.priority = 0;
        this.next = null;
    }

    public PriorityNode(int data, PriorityNode next) {
        this.data = data;
        this.priority = 0;
        this.next = next;
    }

    public PriorityNode(int data, int priority) {
        this.data = data;
        this.priority = priority;
        this.next = null;
    }

    public PriorityNode(int data, int priority, PriorityNode next) {
        this.data = data;
        this.priority = priority;
        this.next = next;
    }

    // Getters
    public int getData() {
        return this.data;
    }

    public int getPriority() {
        return this.priority;
    }

    public PriorityNode getNext() {
        return this.next;
    }

    // Setters
    public void setData(int data) {
        this.data = data;
    }

    public void setPriority(int priority) {
        this.priority = priority;
    }

    public void setNext(PriorityNode next) {
        this.next = next;
    }
}