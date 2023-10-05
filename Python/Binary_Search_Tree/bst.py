class Node:
    # Constructors
    def __init__(self):
        self._data = None
        self._left = None
        self._right = None

    def __init__(self, data):
        self._data = data
        self._left = None
        self._right = None


class BSTree:
    # Constructors
    def __init__(self):
        self._root = None

    # Helper Methods
    def _insert(self, current_node, data):
        if current_node == None:
            return Node(data)

        if data < current_node.data:
            current_node._left = self._insert(data, current_node._left)
        else:
            current_node._right = self._insert(data, current_node._right)

        return current_node

    def _find_ios(self, current_node):
        if current_node._left == None:
            return current_node
        return self._find_ios(current_node._left)

    def _remove(self, current_node, data):
        if current_node == None:
            return current_node

        if data == current_node._data:
            # 2 Children
            if current_node._left != None and current_node._right != None:
                ios = self._find_ios(current_node._right)
                current_node._data = ios._data
                current_node._right = self._remove(ios, ios._data)
            # 1 Child (right)
            elif current_node._right != None:
                return current_node._right
            # 1 Child (left)
            elif current_node._left != None:
                return current_node._left
            # No Children
            else:
                return None

        elif data < current_node._data:
            current_node._left = self._remove(data, current_node._left)
        elif data > current_node._data:
            current_node._right = self._remove(data, current_node._right)

        return current_node

    def _height(self, current_node):
        if current_node == None:
            return 0

        left_height = self._height(current_node._left)
        right_height = self._height(current_node._right)

        if left_height > right_height:
            return left_height + 1
        else:
            return right_height + 1

    def _preorder(self, current_node, string):
        out_string = string
        if current_node == None:
            return ""

        out_string += current_node._data + " "
        self._preorder(current_node._left, out_string)
        self._preorder(current_node._right, out_string)

        return out_string

    def _postorder(self, current_node, string):
        out_string = string
        if current_node == None:
            return ""

        self._postorder(current_node._left, out_string)
        self._postorder(current_node._right, out_string)
        out_string += current_node._data + " "

        return out_string

    def _inorder(self, current_node, string):
        out_string = string
        if current_node == None:
            return ""

        self._inorder(current_node._left, out_string)
        out_string += current_node._data + " "
        self._inorder(current_node._right, out_string)

        return out_string

    # Methods
    def insert(self, data):
        self.root = self._insert(self._root, data)

    def remove(self, data):
        self.root = self._remove(self._root, data)

    def height(self):
        if self._root == None:
            return -1
        return self._height(self._root)

    def preorder(self):
        print(self._preorder(self._root, ""))

    def postorder(self):
        print(self._postorder(self._root, ""))

    def inorder(self):
        print(self._inorder(self._root, ""))

    def search(self, data):
        current_node = self._root
        while current_node != None:
            if data == current_node._data:
                return True
            elif data < current_node._data:
                current_node = current_node._left
            elif data > current_node.data:
                current_node = current_node._right
        return False
