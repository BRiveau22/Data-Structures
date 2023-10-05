class PriorityNode:
    # Constructors
    def __init__(self):
        self._data = 0
        self._priority = 0
        self._next = None

    def __init__(self, data):
        self._data = data
        self._priority = 0
        self._next = None

    def __init__(self, data, priority):
        self._data = data
        self._priority = priority
        self._next = None

    def __init__(self, data, next):
        self._data = data
        self._priority = 0
        self._next = next

    def __init__(self, data, priority, next):
        self._data = data
        self._priority = priority
        self._next = next


class PriorityQueue:
    # Constructors
    def __init__(self):
        self._front = None
        self._back = None
        self._size = 0

    def __init__(self, data):
        self._front = PriorityNode(data)
        self._back = self._front
        self._size = 1

    def __init__(self, list):
        self._front = PriorityNode(list[0])
        self._back = self._front
        self._size = 1

        for i in range(1, len(list)):
            self._back._next = PriorityNode(list[i])
            self._back = self._back._next
            self._size += 1

    # Methods
    def enqueue(self, data, priority):
        if self.is_empty():
            self._front = PriorityNode(data, priority)
            self._back = self._front
            self._size += 1
            return

        if priority < self._front._priority:
            self._front = PriorityNode(data, priority, self._front)
            self._size += 1
            return

        current = self._front
        while current._next != None and current._next.priority <= priority:
            current = current._next

        current._next = PriorityNode(data, priority, current._next)
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty")
            return

        self._front = self._front._next
        self._size -= 1

    def peek(self):
        if self.is_empty():
            print("Queue is empty")
            return -1

        return self._front._data

    def is_empty(self):
        return self._size == 0

    def get_size(self):
        return self._size
