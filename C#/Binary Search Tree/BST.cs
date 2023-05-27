public class BSTNode
{
    #region Properties
    private int _data;
    private BSTNode _left;
    private BSTNode _right;
    #endregion

    #region Constructors
    public BSTNode()
    {
        this._data = 0;
        this._left = null;
        this._right = null;
    }

    public BSTNode(int data)
    {
        this._data = data;
        this._left = null;
        this._right = null;
    }
    #endregion
}

public class BSTree
{
    #region Properties
    private BSTNode _root;
    private int _size;
    #endregion

    #region Constructors
    public BSTree()
    {
        this._root = null;
        this._size = 0;
    }

    #endregion

    #region Private Methods
    private BSTNode insert(BSTNode current_node, int data)
    {
        if (current_node == null)
        {
            return new BSTNode(data);
        }

        if (data < current_node._data)
        {
            current_node._left = this.insert(current_node._left, data);
        }
        else
        {
            current_node._right = this.insert(current_node._right, data);
        }

        return current_node;
    }
    private BSTNode remove(BSTNode current_node, int data)
    {
        if (current_node == null)
        {
            return current_node;
        }

        if (current_node._data == data)
        {
            // 2 children
            if (current_node._left != null && current_node._right != null)
            {
                BSTNode ios = this.find_ios(current_node._right);
                current_node._data = ios._data;
                current_node._right = this.remove(current_node._right, ios._data);
            }
            // 1 child (right)
            else if (current_node._right != null)
            {
                current_node = current_node._right;
            }
            // 1 child (left)
            else if (current_node._left != null)
            {
                current_node = current_node._left;
            }
            // No children
            else
            {
                current_node = null;
            }
        }
        else if (data < current_node._data)
        {
            current_node._left = this.remove(current_node._left, data);
        }
        else
        {
            current_node._right = this.remove(current_node._right, data);
        }

        return current_node;
    }
    private int height(BSTNode root)
    {
        if (root == null)
        {
            return 0;
        }

        int left_height = this.height(root._left);
        int right_height = this.height(root._right);

        return Math.Max(left_height, right_height) + 1;
    }
    private string preorder(BSTNode root, string str)
    {
        string out_str = str;
        if (root == null)
        {
            return "";
        }

        out_str += root._data + " ";
        out_str = this.preorder(root._left, out_str);
        out_str = this.preorder(root._right, out_str);

        return out_str;
    }
    private string inorder(BSTNode root, string str)
    {
        string out_str = str;
        if (root == null)
        {
            return "";
        }

        out_str = this.inorder(root._left, out_str);
        out_str += root._data + " ";
        out_str = this.inorder(root._right, out_str);

        return out_str;
    }
    private void postorder(BSTNode root, string str)
    {
        string out_str = str;
        if (root == null)
        {
            return "";
        }

        out_str = this.postorder(root._left, out_str);
        out_str = this.postorder(root._right, out_str);
        out_str += root._data + " ";

        return out_str;
    }
    private BSTNode find_ios(BSTNode current_node)
    {
        if (current_node._left == null)
        {
            return current_node;
        }

        return this.find_ios(current_node._left);
    }
    private BSTNode find_iop(BSTNode current_node)
    {
        if (current_node._right == null)
        {
            return current_node;
        }

        return this.find_iop(current_node._right);
    }
    #endregion

    #region Public Methods
    public void insert(int data)
    {
        if (!this.search(data))
        {
            this._root = this.insert(this._root, data);
            this._size++;
        }
    }
    public int height()
    {
        return this.height(this._root);
    }
    public void remove(int data)
    {
        if (this.search(data))
        {
            this._root = this.remove(this._root, data);
            this._size--;
        }
    }
    public void preorder()
    {
        print(this.preorder(this._root, ""));
    }
    public void inorder()
    {
        print(this.inorder(this._root, ""));
    }
    public void postorder()
    {
        print(this.postorder(this._root, ""));
    }
    public bool search(int data)
    {
        BSTNode current_node = this._root;

        while (current_node != null)
        {
            if (data == current_node._data)
            {
                return true;
            }
            else if (data < current_node._data)
            {
                current_node = current_node._left;
            }
            else
            {
                current_node = current_node._right;
            }
        }

        return false;
    }
    #endregion
}