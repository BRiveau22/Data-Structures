class Node:
    # Constructors
    def __init__(self):
        self.data = 0
        self.next = None

    def __init__(self, data):
        self.data = data
        self.next = None

    def __init__(self, data, prev):
        self.data = data
        self.next = prev

class Stack:
    # Constructors
    def __init__(self):
        self.top = None
        self.size = 0

    def __init__(self, top):
        self.top = top
        self.size = 1

    def __init__(self, list):
        self.top = Node(list[len(list) - 1])
        self.size = 1

        current = self.top
        for i in range(1, len(list)):
            current.next = Node(list[i])
            current = current.next
            self.size += 1

    # Methods
    def push(self, data):
        if self.top == None:
            self.top = Node(data)
        else:
            self.top = Node(data, self.top)
        self.size += 1

    def pop(self):
        if self.top == None:
            return None
        else:
            data = self.top.data
            self.top = self.top.next
            self.size -= 1
            return data
        
    def peek(self):
        return self.top.data
    
    def size(self):
        return self.size
    
    def is_empty(self):
        return self.size == 0