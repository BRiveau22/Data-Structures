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

public class Linked_List
{
    #region Properties
    private Node _head;
    private int _size;
    #endregion

    #region Constructors
    public Linked_List()
    {
        this._head = null;
        this._size = 0;
    }

    public Linked_List(int data)
    {
        this._head = new Node(data);
        this._size = 1;
    }

    public Linked_List(int[] data)
    {
        this._head = new Node(data[0]);
        this._size = 1;
        Node current = this._head;
        for (int i = 1; i < data.Length; i++)
        {
            current._next = new Node(data[i]);
            current = current._next;
            this._size++;
        }
    }
    #endregion

    #region Methods
    public void push_front(int data)
    {
        this._head = new Node(data, this._head);
    }

    public void push_back(int data)
    {
        Node current = this._head;
        while (current._next != null)
        {
            current = current._next;
        }
        current._next = new Node(data);
    }

    public void insert(int data, int idx)
    {
        if (idx <= 0)
        {
            this.push_front(data);
        }
        else if (idx >= this._size)
        {
            this.push_back(data);
        }
        else
        {
            Node current = this._head;
            for (int i = 0; i < idx - 1; i++)
            {
                current = current._next;
            }
            current._next = new Node(data, current._next);
        }
    }

    public void remove(int data)
    {
        Node current = this._head;
        while (current._next != null)
        {
            if (current.next.data == data)
            {
                current._next = current.next.next;
                return;
            }
            current = current._next;
        }
    }

    public bool contains(int data)
    {
        Node current = this._head;
        while (current._next != null)
        {
            if (current._data == data)
            {
                return true;
            }
            current = current._next;
        }
        return false;
    }

    public void print()
    {
        Node current = this._head;
        while (current != null)
        {
            Console.Write(current._data + " ");
            current = current._next;
        }
        Console.WriteLine();
    }
    #endregion
}