class Node:
    # Constructors
    def __init__(self):
        self.data = 0
        self.next = None

    def __init__(self, data):
        self.data = data
        self.next = None

    def __init__(self, data, next):
        self.data = data
        self.next = next


class Queue:
    # Constructors
    def __init__(self):
        self.front = None
        self.back = None
        self.size = 0

    def __init__(self, data):
        self.front = Node(data)
        self.back = self.front
        self.size = 1

    def __init__(self, list):
        self.front = Node(list[0])
        self.back = self.front
        self.size = 1

        for i in range(1, len(list)):
            self.back.next = Node(list[i])
            self.back = self.back.next
            self.size += 1

    # Methods
    def enqueue(self, data):
        if self.size == 0:
            self.front = Node(data)
            self.back = self.front
            self.size += 1
            return

        self.back.next = Node(data)
        self.back = self.back.next
        self.size += 1

    def dequeue(self):
        if self.size == 0:
            print("Queue is empty")
            return

        self.front = self.front.next
        self.size -= 1

    def peek(self):
        if self.size == 0:
            print("Queue is empty")
            return -1

        return self.front.data

    def get_size(self):
        return self.size

    def is_empty(self):
        return self.size == 0
