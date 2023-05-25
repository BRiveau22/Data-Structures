class Node:
    # Constructors
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BSTree:
    # Constructors
    def __init__(self):
        self.root = None

    # Helper Methods
    def _insert(self, current_node, data):
        if current_node == None:
            return Node(data)

        if data < current_node.data:
            current_node.left = self._insert(data, current_node.left)
        else:
            current_node.right = self._insert(data, current_node.right)

        return current_node

    def _find_ios(self, current_node):
        if current_node.left == None:
            return current_node
        return self._find_ios(current_node.left)

    def _find_iop(self, current_node):
        if current_node.right == None:
            return current_node
        return self._find_iop(current_node.right)

    def _remove(self, current_node, data):
        if current_node == None:
            return current_node

        if data == current_node.data:
            # 2 Children
            if current_node.left != None and current_node.right != None:
                ios = self._find_ios(current_node.right)
                current_node.data = ios.data
                current_node.right = self._remove(ios, ios.data)
            # 1 Child (right)
            elif current_node.right != None:
                return current_node.right
            # 1 Child (left)
            elif current_node.left != None:
                return current_node.left
            # No Children
            else:
                return None

        elif data < current_node.data:
            current_node.left = self._remove(data, current_node.left)
        elif data > current_node.data:
            current_node.right = self._remove(data, current_node.right)

        return current_node

    def _height(self, current_node):
        if current_node == None:
            return 0

        left_height = self._height(current_node.left)
        right_height = self._height(current_node.right)

        if left_height > right_height:
            return left_height + 1
        else:
            return right_height + 1

    def _preorder(self, current_node, string):
        out_string = string
        if current_node == None:
            return ""

        out_string += current_node.data + " "
        self._preorder(current_node.left, out_string)
        self._preorder(current_node.right, out_string)

        return out_string

    def _postorder(self, current_node, string):
        out_string = string
        if current_node == None:
            return ""

        self._postorder(current_node.left, out_string)
        self._postorder(current_node.right, out_string)
        out_string += current_node.data + " "

        return out_string

    def _inorder(self, current_node, string):
        out_string = string
        if current_node == None:
            return ""

        self._inorder(current_node.left, out_string)
        out_string += current_node.data + " "
        self._inorder(current_node.right, out_string)

        return out_string

    # Methods
    def insert(self, data):
        self.root = self._insert(self.root, data)

    def remove(self, data):
        self.root = self._remove(self.root, data)

    def height(self):
        if self.root == None:
            return -1
        return self._height(self.root)

    def preorder(self):
        print(self._preorder(self.root, ""))

    def postorder(self):
        print(self._postorder(self.root, ""))

    def inorder(self):
        print(self._inorder(self.root, ""))

    def search(self, data):
        current_node = self.root
        while current_node != None:
            if data == current_node.data:
                return True
            elif data < current_node.data:
                current_node = current_node.left
            elif data > current_node.data:
                current_node = current_node.right
        return False
