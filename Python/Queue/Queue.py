class Node:
    # Constructors
    def __init__(self):
        self._data = 0
        self._next = None

    def __init__(self, data):
        self._data = data
        self._next = None

    def __init__(self, data, next):
        self._data = data
        self._next = next


class Queue:
    # Constructors
    def __init__(self):
        self._front = None
        self._back = None
        self._size = 0

    def __init__(self, data):
        self._front = Node(data)
        self._back = self._front
        self._size = 1

    def __init__(self, list):
        self._front = Node(list[0])
        self._back = self._front
        self._size = 1

        for i in range(1, len(list)):
            self._back._next = Node(list[i])
            self._back = self._back._next
            self._size += 1

    # Methods
    def enqueue(self, data):
        if self._size == 0:
            self._front = Node(data)
            self._back = self._front
            self._size += 1
            return

        self._back._next = Node(data)
        self._back = self._back._next
        self._size += 1

    def dequeue(self):
        if self._size == 0:
            print("Queue is empty")
            return

        self._front = self._front._next
        self._size -= 1

    def peek(self):
        if self._size == 0:
            print("Queue is empty")
            return -1

        return self._front._data

    def get_size(self):
        return self._size

    def is_empty(self):
        return self._size == 0
