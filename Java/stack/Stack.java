package stack;

public class Stack {
    private Node top;
    private int size;

    // Constructors
    public Stack() {
        this.top = null;
        this.size = 0;
    }

    public Stack(int data){
        this.top = new Node(data);
        this.size = 1;
    }

    public Stack(int[] list){
        this.top = new Node(list[0]);
        this.size = 1;

        Node currentNode = this.top;
        for (int i = 1; i < list.length; i++){
            currentNode.setNext(new Node(list[i]));
            currentNode = currentNode.getNext();
            this.size++;
        }
    }

    // Methods
    public void push(int data){
        Node newNode = new Node(data);
        newNode.setNext(this.top);
        this.top = newNode;
        this.size++;
    }

    public int pop(){
        if(!this.isEmpty()){
            int tempData = this.top.getData();
            this.top = this.top.getNext();
            this.size--;
            return tempData;
        }

        return -1;
    }

    public int peek(){
        if(!this.isEmpty()){
            return this.top.getData();
        }

        return -1;
    }

    public int size(){
        return this.size;
    }

    public boolean isEmpty(){
        return this.size == 0;
    }
}
