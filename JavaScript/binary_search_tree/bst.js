class BSTNode {
    // Constructors
    constructor() {
        this._value = 0;
        this._left = null;
        this._right = null;
    }

    constructor(value) {
        this._value = value;
        this._left = null;
        this._right = null;
    }
}

class BST {
    // Constructors
    constructor() {
        this._root = null;
        this._size = 0;
    }

    // Helper Methods
    _insert(node, value) {
        if (node == null) {
            return BSTNode(value);
        }

        if (data < node._data) {
            node._left = this._insert(node._left, data);
        }
        else {
            node._right = this._insert(node._right, data);
        }

        return node;
    }

    _remove(node, value) {
        if (node == null) {
            return node;
        }

        if (value == node._data) {
            // 2 Children
            if (node._left != null && node._right != null) {
                const ios = this._findIOS(node._right);
                node._data = ios._data;
                node._right = this._remove(node._right, ios._data);
            }
            // 1 Child (right)
            else if (node._right != null) {
                return node._right;
            }
            // 1 Child (left)
            else if (node._left != null) {
                return node._left;
            }
            // No Children
            else {
                return null;
            }
        }
        else if (value < node._data) {
            node._left = this._remove(node._left, value);
        }
        else {
            node._right = this._remove(node._right, value);
        }

        return node;
    }

    _findIOS(node) {
        if (node._left == null) {
            return node;
        }

        return this._findIOS(node._left);
    }

    _height(root) {
        if (root == null) {
            return 0;
        }

        const leftHeight = this._height(root._left);
        const rightHeight = this._height(root._right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    _preorder(root, string) {
        let outString = string;
        if (root == null) {
            return "";
        }

        outString += root._data + " ";
        this._preorder(root._left, outString);
        this._preorder(root._right, outString);

        return outString;
    }

    _inorder(root, string) {
        let outString = string;
        if (root == null) {
            return "";
        }

        this._inorder(root._left, outString);
        outString += root._data + " ";
        this._inorder(root._right, outString);

        return outString;
    }

    _postorder(root, string) {
        let outString = string;
        if (root == null) {
            return "";
        }

        this._postorder(root._left, outString);
        this._postorder(root._right, outString);
        outString += root._data + " ";

        return outString;
    }

    // Methods
    insert(value) {
        this.root = this._insert(this._root, value);
    }

    remove(value) {
        this.root = this._remove(this._root, value);
    }

    height() {
        if (this._root == null) {
            return -1;
        }

        return this._height(this._root);
    }

    preorder() {
        console.log(this._preorder(this._root, ""));
    }

    inorder() {
        console.log(this._inorder(this._root, ""));
    }

    postorder() {
        console.log(this._postorder(this._root, ""));
    }

    search(value) {
        let currentNode = this._root;
        while (currentNode != null) {
            if (currentNode._data == value) {
                return true;
            }
            else if (value < currentNode._data) {
                currentNode = currentNode._left;
            }
            else {
                currentNode = currentNode._right;
            }
        }

        return false;
    }
}