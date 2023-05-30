public class Node
{
    #region Properties
    private int _data;
    private Node _next;
    #endregion

    #region Constructors
    public Node()
    {
        this._data = 0;
        this._next = null;
    }

    public Node(int data)
    {
        this._data = data;
        this._next = null;
    }

    public Node(int data, Node next)
    {
        this._data = data;
        this._next = next;
    }
    #endregion
}

public class Queue
{
    #region Properties
    private Node _front;
    private Node _back;
    private int _size;
    #endregion

    #region Constructors
    public Queue()
    {
        this._front = null;
        this._back = null;
        this._size = 0;
    }

    public Queue(int data)
    {
        this._front = Node(data);
        this._back = this._front;
        this._size = 1;
    }

    public Queue(int[] arr)
    {
        this._front = Node(arr[0]);
        this._back = this._front;
        this._size = 1;
        for (int i = 1; i < arr.Length; i++)
        {
            this._back._next = Node(arr[i]);
            this._back = this._back._next;
            this._size++;
        }
    }
    #endregion

    #region Methods
    public void enqueue(int date)
    {
        if (this._size == 0)
        {
            this._front = Node(data);
            this._back = this._front;
            this._size = 1;
            return;
        }

        this._back._next = Node(data);
        this._back = this._back._next;
        this._size++;
    }

    public void dequeue()
    {
        if (this._size == 0)
        {
            print("Queue is empty");
            return;
        }

        this._front = this._front._next;
        this._size--;
    }

    public int peek()
    {
        if (this._size == 0)
        {
            print("Queue is empty");
            return -1;
        }
        return this._front._data;
    }

    public int get_size()
    {
        return this._size;
    }
    #endregion
}