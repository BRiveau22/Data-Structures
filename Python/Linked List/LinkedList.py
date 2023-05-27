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


class LinkedList:
    # Contstructors
    def __init__(self):
        self._head = None
        self._size = 0

    def __init__(self, head):
        self._head = head
        self._size = 0

    def __init__(self, list):
        self._head = Node(list[0])
        self._size = 1

        current = self._head
        for i in range(1, len(list)):
            current._next = Node(list[i])
            current = current.getNext()
            self._size += 1

    # Methods
    def push_front(self, data):
        self._head = Node(data, self._head)

    def push_back(self, data):
        current = self._head

        while current._next() != None:
            current = current._next

        current._next = Node(data)

    def insert(self, data, idx):
        if idx <= 0:
            self.push_front(data)
        elif idx >= self._size:
            self.push_back(data)
        else:
            current = self._head
            for i in range(idx):
                current = current._next

            current._next = Node(data, current._next)

    def remove(self, data):
        current = self._head
        while current._next != None:
            if current._next.data == data:
                current._next = current._next.next
                return
            current = current._next

    def contains(self, data):
        current = self._head
        while current._next != None:
            if current._data == data:
                return True
            current = current._next
        return False

    def print(self):
        current = self._head
        while current != None:
            print(current._data + " ")
            current = current._next
