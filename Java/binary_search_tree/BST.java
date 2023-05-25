package binary_search_tree;

public class BST {
    private BSTNode root;

    // Constructor
    public BST() {
        this.root = null;
    }

    // Private Methods
    private BSTNode insert(BSTNode current, int data) {
        if (current == null) {
            return new BSTNode(data);
        }

        if (data < current.getData()) {
            current.setNodeLeft(this.insert(current.getNodeLeft(), data));
        } else {
            current.setNodeRight(this.insert(current.getNodeRight(), data));
        }

        return current;
    }

    private BSTNode remove(BSTNode current, int data) {
        if (current == null) {
            return null;
        }

        if (current.getData() == data) {
            // 2 children
            if (current.getNodeRight() != null && current.getNodeLeft() != null) {
                BSTNode ios = this.findIOS(current.getNodeRight());
                current.setData(ios.getData());
                current.setNodeRight(this.remove(current.getNodeRight(), ios.getData()));
            }

            // 1 child (right)
            else if (current.getNodeRight() != null) {
                current = current.getNodeRight();
            }
            // 1 child (left)
            else if (current.getNodeLeft() != null) {
                current = current.getNodeLeft();
            }

            // 0 children
            else {
                current = null;
            }
        } else if (data < current.getData()) {
            current.setNodeLeft(this.remove(current.getNodeLeft(), data));
        } else {
            current.setNodeRight(this.remove(current.getNodeRight(), data));
        }

        return current;
    }

    private int height(BSTNode root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = this.height(root.getNodeLeft());
        int rightHeight = this.height(root.getNodeRight());

        // Returns the greater of the two heights
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }

    private String preorder(BSTNode root) {
        String outString = "";

        if (root != null) {
            outString += root.getData() + " ";
            outString += this.preorder(root.getNodeLeft());
            outString += this.preorder(root.getNodeRight());
        }

        return outString;
    }

    private String inorder(BSTNode root) {
        String outString = "";

        if (root != null) {
            outString += this.inorder(root.getNodeLeft());
            outString += root.getData() + " ";
            outString += this.inorder(root.getNodeRight());
        }

        return outString;
    }

    private String postorder(BSTNode root) {
        String outString = "";

        if (root != null) {
            outString += this.postorder(root.getNodeLeft());
            outString += this.postorder(root.getNodeRight());
            outString += root.getData() + " ";
        }

        return outString;
    }

    private BSTNode findIOS(BSTNode root) {
        while (root.getNodeLeft() != null) {
            root = root.getNodeLeft();
        }

        return root;
    }

    // Public Methods
    public void insert(int data) {
        if (!this.search(data)) {
            this.root = this.insert(this.root, data);
        }
    }

    public int height() {
        if (this.root == null) {
            return -1;
        }

        return this.height(this.root);
    }

    public void remove(int data) {
        if (this.search(data)) {
            this.root = this.remove(this.root, data);
        }
    }

    public void preorder() {
        System.out.println(this.preorder(this.root));
    }

    public void inorder() {
        System.out.println(this.inorder(this.root));
    }

    public void postorder() {
        System.out.println(this.postorder(this.root));
    }

    public boolean search(int data) {
        BSTNode current = this.root;
        while (current != null) {
            if (current.getData() == data) {
                return true;
            } else if (data < current.getData()) {
                current = current.getNodeLeft();
            } else {
                current = current.getNodeRight();
            }
        }
        return false;
    }
}