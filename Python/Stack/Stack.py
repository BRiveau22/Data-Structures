class Node:
    # Constructors
    def __init__(self):
        self._data = 0
        self._next = None

    def __init__(self, data):
        self._data = data
        self._next = None

    def __init__(self, data, prev):
        self._data = data
        self._next = prev


class Stack:
    # Constructors
    def __init__(self):
        self._top = None
        self._size = 0

    def __init__(self, top):
        self._top = top
        self._size = 1

    def __init__(self, list):
        self._top = Node(list[len(list) - 1])
        self._size = 1

        current = self._top
        for i in range(1, len(list)):
            current._next = Node(list[i])
            current = current._next
            self._size += 1

    # Methods
    def push(self, data):
        if self._top == None:
            self._top = Node(data)
        else:
            self._top = Node(data, self._top)
        self._size += 1

    def pop(self):
        if self._top == None:
            return None
        else:
            data = self._top._data
            self._top = self._top._next
            self._size -= 1
            return data

    def peek(self):
        return self._top._data

    def _size(self):
        return self._size

    def is_empty(self):
        return self._size == 0
