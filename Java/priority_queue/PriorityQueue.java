package priority_queue;

public class PriorityQueue{
    private PriorityNode front;
    private PriorityNode back;
    private int size;


    // Constructors
    public PriorityQueue(){
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    public PriorityQueue(int data){
        this.front = new PriorityNode(data);
        this.back = this.front;
        this.size = 1;
    }

    public PriorityQueue(int[] arr){
        this.front = new PriorityNode(arr[0]);
        this.back = this.front;
        this.size = 1;
        for (int i = 1; i < arr.length; i++) {
            this.back.setNext(new PriorityNode(arr[i]));
            this.back = this.back.getNext();
            this.size++;
        }
    }

    // Methods
    public void enqueue(int data, int priority){
        PriorityNode newNode = new PriorityNode(data, priority);
        if(this.size == 0){
            this.front = newNode;
            this.back = newNode;
        }
        else {
            PriorityNode current = this.front;
            while (current.getNext() != null && current.getNext().getPriority() <= priority) {
                current = current.getNext();
            }
            if (current == this.front && current.getPriority() > priority) {
                newNode.setNext(current);
                this.front = newNode;
            }
            else if (current == this.back && current.getPriority() <= priority) {
                current.setNext(newNode);
                this.back = newNode;
            }
            else {
                newNode.setNext(current.getNext());
                current.setNext(newNode);
            }
        }

        this.size++;
    }

    public void dequeue(){
        if(this.size == 0){
            System.out.println("Queue is empty");
            return;
        }

        if(this.size == 1){
            this.front = null;
            this.back = null;
            this.size--;
            return;
        }
        
        this.front = this.front.getNext();
        this.size--;
    }

    public int peek(){
        if(this.size == 0){
            System.out.println("Queue is empty");
            return -1;
        }

        return this.front.getData();
    }

    public int getSize(){
        return this.size;
    }
}