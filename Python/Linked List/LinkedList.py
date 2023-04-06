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

class LinkedList:
    # Contstructors
    def __init__(self):
        self.head = None
        self.size = 0

    def __init__(self, head):
        self.head = head
        self.size = 0

    def __init__(self, list):
        self.head = Node(list[0])
        self.size = 1

        current = self.head
        for i in range(1, len(list)):
            current.next = Node(list[i])
            current = current.getNext()
            self.size += 1

    # Methods
    def push_front(self, data):
        self.head = Node(data, self.head)

    def push_back(self, data):
        current = self.head

        while current.next() != None:
            current = current.next
        
        current.next = Node(data)

    def insert(self, data, idx):
        if idx <= 0:
            self.push_front(data)
        elif idx >= self.size:
            self.push_back(data)
        else:
            current = self.head
            for i in range(idx):
                current = current.next

            current.next = Node(data, current.next)

    def remove(self, data):
        current = self.head
        while(current.next != None):
            if current.next.data == data:
                current.next = current.next.next
                return
            current = current.next

    def contains(self, data):
        current = self.head
        while current.next != None:
            if current.data == data:
                return True
            current = current.next
        return False
    
    def print(self):
        current = self.head
        while current != None:
            print(current.data + ' ')
            current = current.next