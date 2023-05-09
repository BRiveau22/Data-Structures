class BSTNode{
    // Constructors
    constructor(){
        this.value = 0;
        this.left = null;
        this.right = null;
    }

    constructor(value){
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BST{
    // Constructors
    constructor(){
        this.root = null;
        this.size = 0;
    }

    // Helper Methods
    _insert(node, value){
        if (node == null){
            return Node(value);
        }

        if (data < node.data){
            node.left = this._insert(node.left, data);
        }
        else {
            node.right = this._insert(node.right, data);
        }

        return node;
    }

    _remove(node, value){
        if(node == null){
            return node;
        }

        if(value == node.data){
            // 2 Children
            if(node.left != null && node.right != null){
                let ios = this._findIOS(node.right);
                node.data = ios.data;
                node.right = this._remove(node.right, ios.data);
            }
            // 1 Child (right)
            else if(node.right != null){
                return node.right;
            }
            // 1 Child (left)
            else if(node.left != null){
                return node.left;
            }
            // No Children
            else {
                return null;
            }
        }
        else if(value < node.data){
            node.left = this._remove(node.left, value);
        }
        else {
            node.right = this._remove(node.right, value);
        }

        return node;
    }

    _findIOS(node){
        if(node.left == null){
            return node;
        }

        return this._findIOS(node.left);
    }

    _findIOP(node){
        if(node.right == null){
            return node;
        }

        return this._findIOP(node.right);
    }

    _height(root){
        if(root == null){
            return 0;
        }

        let left_height = this._height(root.left);
        let right_height = this._height(root.right);

        return Math.max(left_height, right_height) + 1;
    }

    _preorder(root, string){
        let outString = string;
        if (root == null){
            return "";
        }

        outString += root.data + " ";
        this._preorder(root.left, outString);
        this._preorder(root.right, outString);

        return outString;
    }

    _inorder(root, string){
        let outString = string;
        if (root == null){
            return "";
        }

        this._inorder(root.left, outString);
        outString += root.data + " ";
        this._inorder(root.right, outString);

        return outString;
    }

    _postorder(root, string){
        let outString = string;
        if (root == null){
            return "";
        }

        this._postorder(root.left, outString);
        this._postorder(root.right, outString);
        outString += root.data + " ";

        return outString;
    }

    // Methods
    insert(value){
        this.root = this._insert(this.root, value);
    }

    remove(value){
        this.root = this._remove(this.root, value);
    }

    height(){
        if(this.root == null){
            return -1;
        }

        return this._height(this.root);
    }

    preorder(){
        print(this._preorder(this.root, ""));
    }

    inorder(){
        print(this._inorder(this.root, ""));
    }

    postorder(){
        print(this._postorder(this.root, ""));
    }

    search(value){
        current_node = this.root;
        while(current_node != null){
            if(current_node.data == value){
                return true;
            }
            else if(value < current_node.data){
                current_node = current_node.left;
            }
            else {
                current_node = current_node.right;
            }
        }

        return false;
    }
}