public class Priority_Node
{
    #region Properties
    private int _data;
    private int _priority;
    private Priority_Node _next;
    #endregion

    #region Constructors
    public Priority_Node()
    {
        this._data = 0;
        this._priority = 0;
        this._next = null;
    }

    public Priority_Node(int data)
    {
        this._data = data;
        this._priority = 0;
        this._next = null;
    }

    public Priority_Node(int data, int priority)
    {
        this._data = data;
        this._priority = priority;
        this._next = null;
    }

    public Priority_Node(int data, Priority_Node next)
    {
        this._data = data;
        this._priority = 0;
        this._next = next;
    }

    public Priority_Node(int data, int priority, Priority_Node next)
    {
        this._data = data;
        this._priority = priority;
        this._next = next;
    }
    #endregion
}

public class Priority_Queue
{
    #region Properties
    private Priority_Node _front;
    private Priority_Node _back;
    private int _size;
    #endregion

    #region Constructors
    public Priority_Queue()
    {
        this._front = null;
        this._back = null;
        this._size = 0;
    }

    public Priority_Queue(int data)
    {
        this._front = new Priority_Node(data);
        this._back = this._front;
        this._size = 1;
    }

    public Priority_Queue(int[] arr)
    {
        this._front = new Priority_Node(arr[0]);
        this._back = this._front;
        this._size = 1;
        for (int i = 1; i < arr.Length; i++)
        {
            this._back._next = new Priority_Node(arr[i]);
            this._back = this._back._next;
            this._size++;
        }
    }
    #endregion

    #region Methods
    public void enqueue(int data, int priority)
    {
        if (this._size == 0)
        {
            this._front = new Priority_Node(data, priority);
            this._back = this._front;
            this._size = 1;
            return;
        }

        Priority_Node temp = this._front;
        Priority_Node prev = null;
        while (temp != null && temp._priority >= priority)
        {
            prev = temp;
            temp = temp._next;
        }

        if (prev == null)
        {
            this._front = new Priority_Node(data, priority, this._front);
            this._size++;
            return;
        }

        prev._next = new Priority_Node(data, priority, temp);
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