public class Priority_Node
{
    private int data;
    private int priority;
    private Priority_Node next;

    // Constructors
    public Priority_Node()
    {
        this.data = 0;
        this.priority = 0;
        this.next = null;
    }

    public Priority_Node(int data)
    {
        this.data = data;
        this.priority = 0;
        this.next = null;
    }

    public Priority_Node(int data, int priority)
    {
        this.data = data;
        this.priority = priority;
        this.next = null;
    }

    public Priority_Node(int data, Priority_Node next)
    {
        this.data = data;
        this.priority = 0;
        this.next = next;
    }

    public Priority_Node(int data, int priority, Priority_Node next)
    {
        this.data = data;
        this.priority = priority;
        this.next = next;
    }
}

public class Priority_Queue
{
    private Priority_Node front;
    private Priority_Node back;
    private int size;

    public Priority_Queue()
    {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    public Priority_Queue(int data)
    {
        this.front = new Priority_Node(data);
        this.back = this.front;
        this.size = 1;
    }

    public Priority_Queue(int[] arr)
    {
        this.front = new Priority_Node(arr[0]);
        this.back = this.front;
        this.size = 1;
        for (int i = 1; i < arr.Length; i++)
        {
            this.back.next = new Priority_Node(arr[i]);
            this.back = this.back.next;
            this.size++;
        }
    }

    public void enqueue(int data, int priority)
    {
        if (this.size == 0)
        {
            this.front = new Priority_Node(data, priority);
            this.back = this.front;
            this.size = 1;
            return;
        }

        Priority_Node temp = this.front;
        Priority_Node prev = null;
        while (temp != null && temp.priority >= priority)
        {
            prev = temp;
            temp = temp.next;
        }

        if (prev == null)
        {
            this.front = new Priority_Node(data, priority, this.front);
            this.size++;
            return;
        }

        prev.next = new Priority_Node(data, priority, temp);
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