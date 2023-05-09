public class BSTNode{
    private int data;
    private BSTNode left;
    private BSTNode right;

    // Constructors
    public BSTNode(){
        this.data = 0;
        this.left = null;
        this.right = null;
    }

    public BSTNode(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BSTree{
    private BSTNode root;
    private int size;

    // Constructors
    public BSTree(){
        this.root = null;
        this.size = 0;
    }

    // Private Methods
    private BSTNode insert(BSTNode current_node, int data){
        if(current_node == null){
            return new BSTNode(data);
        }

        if(data < current_node.data){
            current_node.left = this.insert(current_node.left, data);
        }
        else {
            current_node.right = this.insert(current_node.right, data);
        }

        return current_node;
    }
	private BSTNode remove(BSTNode current_node, int data){
        if(current_node == null){
            return current_node;
        }

        if(current_node.data == data){
            // 2 children
            if(current_node.left != null && current_node.right != null){
                BSTNode ios = this.find_ios(current_node.right);
                current_node.data = ios.data;
                current_node.right = this.remove(current_node.right, ios.data);
            }
            // 1 child (right)
            else if(current_node.right != null){
                current_node = current_node.right;
            }
            // 1 child (left)
            else if(current_node.left != null){
                current_node = current_node.left;
            }
            // No children
            else {
                current_node = null;
            }
        }
        else if (data < current_node.data){
            current_node.left = this.remove(current_node.left, data);
        }
        else {
            current_node.right = this.remove(current_node.right, data);
        }

        return current_node;
    }
	private int height(BSTNode root){
        if(root == null){
            return 0;
        }

        int left_height = this.height(root.left);
        int right_height = this.height(root.right);

        return Math.Max(left_height, right_height) + 1;
    }
	private string preorder(BSTNode root, string str){
        string out_str = str;
        if(root == null){
            return "";
        }

        out_str += root.data + " ";
        out_str = this.preorder(root.left, out_str);
        out_str = this.preorder(root.right, out_str);

        return out_str;
    }
	private string inorder(BSTNode root, string str){
        string out_str = str;
        if(root == null){
            return "";
        }

        out_str = this.inorder(root.left, out_str);
        out_str += root.data + " ";
        out_str = this.inorder(root.right, out_str);

        return out_str;
    }
	private void postorder(BSTNode root, string str){
        string out_str = str;
        if(root == null){
            return "";
        }

        out_str = this.postorder(root.left, out_str);
        out_str = this.postorder(root.right, out_str);
        out_str += root.data + " ";

        return out_str;
    }
	private BSTNode find_ios(BSTNode current_node){
        if(current_node.left == null){
            return current_node;
        }

        return this.find_ios(current_node.left);
    }
	private BSTNode find_iop(BSTNode current_node){
        if(current_node.right == null){
            return current_node;
        }

        return this.find_iop(current_node.right);
    }

    // Public Methods
    public void insert(int data){
        if(!this.search(data)){
            this.root = this.insert(this.root, data);
            this.size++;
        }
    }
	public int height(){
        return this.height(this.root);
    }
	public void remove(int data){
        if(this.search(data)){
            this.root = this.remove(this.root, data);
            this.size--;
        }
    }
	public void preorder(){
        print(this.preorder(this.root, ""));
    }
	public void inorder(){
        print(this.inorder(this.root, ""));
    }
	public void postorder(){
        print(this.postorder(this.root, ""));
    }
	public bool search(int data){
        BSTNode current_node = this.root;

        while(current_node != null){
            if (data == current_node.data){
                return true;
            }
            else if (data < current_node.data){
                current_node = current_node.left;
            }
            else {
                current_node = current_node.right;
            }
        }

        return false;
    }
}