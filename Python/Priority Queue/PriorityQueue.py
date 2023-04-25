class PriorityNode:
    # Constructors
    def __init__(self):
        self.data = 0
        self.priority = 0
        self.next = None

    def __init__(self, data):
        self.data = data
        self.priority = 0
        self.next = None

    def __init__(self, data, priority):
        self.data = data
        self.priority = priority
        self.next = None

    def __init__(self, data, next):
        self.data = data
        self.priority = 0
        self.next = next

    def __init__(self, data, priority, next):
        self.data = data
        self.priority = priority
        self.next = next

class PriorityQueue:
    # Constructors
    def __init__(self):
        self.front = None
        self.back = None
        self.size = 0

    def __init__(self, data):
        self.front = PriorityNode(data)
        self.back = self.front
        self.size = 1

    def __init__(self, list):
        self.front = PriorityNode(list[0])
        self.back = self.front
        self.size = 1

        for i in range(1, len(list)):
            self.back.next = PriorityNode(list[i])
            self.back = self.back.next
            self.size += 1

    # Methods
    def enqueue(self, data, priority):
        if(self.is_empty()):
            self.front = PriorityNode(data, priority)
            self.back = self.front
            self.size += 1
            return

        if(priority < self.front.priority):
            self.front = PriorityNode(data, priority, self.front)
            self.size += 1
            return

        current = self.front
        while(current.next != None and current.next.priority <= priority):
            current = current.next

        current.next = PriorityNode(data, priority, current.next)
        self.size += 1

    def dequeue(self):
        if(self.is_empty()):
            print("Queue is empty")
            return

        self.front = self.front.next
        self.size -= 1

    def peek(self):
        if(self.is_empty()):
            print("Queue is empty")
            return -1

        return self.front.data
    
    def is_empty(self):
        return self.size == 0
    
    def get_size(self):
        return self.size
