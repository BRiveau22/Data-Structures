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

public class Stack
{
    #region Properties
    private Node _top;
    private int _size;
    #endregion

    #region Constructors
    public Stack()
    {
        this._top = null;
        this.size = 0;
    }

    public Stack(int data)
    {
        this._top = new Node(data);
        this.size = 1;
    }

    public Stack(int[] data)
    {
        this._top = new Node(data[0]);
        this.size = 1;

        Node current = this._top;
        for (int i = 0; i < data.Length; i++)
        {
            current._next = new Node(data[i]);
            current = current._next;
            this.size++;
        }
    }
    #endregion

    #region Methods
    public void push(int data)
    {
        Node newNode = new Node(data);
        newNode._next = this._top;
        this._top = newNode;
        this.size++;
    }

    public int pop()
    {
        if (!isEmpty)
        {
            int data = this._top._data;
            this._top = this._top._next;
            this.size--;
            return data;
        }

        return -1;
    }

    public int peek()
    {
        if (!isEmpty)
        {
            return this._top._data;
        }

        return -1;
    }

    public bool isEmpty()
    {
        return this.size == 0;
    }

    public int size()
    {
        return this.size;
    }
    #endregion
}