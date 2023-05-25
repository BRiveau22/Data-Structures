public class Node
{
    private int data;
    private Node next;

    // Constructors
    public Node()
    {
        this.data = 0;
        this - ndext = null;
    }

    public Node(int data)
    {
        this.data = data;
        this.next = null;
    }

    public Node(int data, Node next)
    {
        this.data = data;
        this.next = next;
    }
}

public class Queue
{
    private Node front;
    private Node back;
    private int size;

    // Constructors
    public Queue()
    {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    public Queue(int data)
    {
        this.front = Node(data);
        this.back = this.front;
        this.size = 1;
    }

    public Queue(int[] arr)
    {
        this.front = Node(arr[0]);
        this.back = this.front;
        this.size = 1;
        for (int i = 1; i < arr.Length; i++)
        {
            this.back.next = Node(arr[i]);
            this.back = this.back.next;
            this.size++;
        }
    }

    public void enqueue(int date)
    {
        if (this.size == 0)
        {
            this.front = Node(data);
            this.back = this.front;
            this.size = 1;
            return;
        }

        this.back.next = Node(data);
        this.back = this.back.next;
        this.size++;
    }

    public void dequeue()
    {
        if (this.size == 0)
        {
            print("Queue is empty");
            return;
        }

        this.front = this.front.next;
        this.size--;
    }

    public int peek()
    {
        if (this.size == 0)
        {
            print("Queue is empty");
            return -1;
        }
        return this.front.data;
    }

    public int get_size()
    {
        return this.size;
    }
}