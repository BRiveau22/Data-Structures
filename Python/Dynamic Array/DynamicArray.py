class DynamicArray:
    # Constructors
    def __init__(self):
        self.data = []
        self.length = 0
        self.capacity = 1
        self.scale_factor = 2

    def __init__(self, data):
        self.data = data
        self.length = len(data)
        self.capacity = self.size
        self.scale_factor = 2

    def __init__(self, scale_factor, capacity):
        self.data = []
        self.length = 0
        self.capacity = capacity
        self.scale_factor = scale_factor

    def __init__(self, scale_factor, length, default_value):
        self.data = [default_value] * length
        self.length = length
        self.capacity = length
        self.scale_factor = scale_factor

    def __init__(self, data, scale_factor):
        self.data = data
        self.length = len(data)
        self.capacity = self.size
        self.scale_factor = scale_factor

    # Methods
    def resize(self):
        temp = [] * self.capacity * self.scale_factor
        for i in range(self.length):
            temp[i] = self.data[i]

        self.data = temp
        self.capacity *= self.scale_factor

    def append(self, value):
        if self.length == self.capacity:
            self.resize()

        self.data[self.length] = value
        self.length += 1

    def prepend(self, value):
        if self.length == self.capacity:
            self.resize()

        for i in range(1, self.length + 1):
            self.data[i] = self.data[i - 1]

        self.data[0] = value
        self.length += 1

    def insert(self, idx, value):
        if idx < 1:
            self.prepend(value)
            return

        if idx >= self.length:
            self.append(value)
            return

        if self.length == self.capacity:
            self.resize()

        for i in range(idx, self.length + 1):
            self.data[i] = self.data[i - 1]

        self.data[idx] = value
        self.length += 1

    def find_first(self, data):
        for i in range(self.length):
            if self.data[i] == data:
                return i

        return -1

    def find_last(self, data):
        for i in range(self.length - 1, -1, -1):
            if self.data[i] == data:
                return i

        return -2

    def exists(self, data):
        return self.find_first(data) != -1
