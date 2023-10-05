class DynamicArray:
    # Constructors
    def __init__(self):
        self._data = []
        self._length = 0
        self._capacity = 1
        self._scale_factor = 2

    def __init__(self, data):
        self._data = data
        self._length = len(data)
        self._capacity = self.size
        self._scale_factor = 2

    def __init__(self, scale_factor, capacity):
        self._data = []
        self._length = 0
        self._capacity = capacity
        self._scale_factor = scale_factor

    def __init__(self, scale_factor, length, default_value):
        self._data = [default_value] * length
        self._length = length
        self._capacity = length
        self._scale_factor = scale_factor

    def __init__(self, data, scale_factor):
        self._data = data
        self._length = len(data)
        self._capacity = self._data.size
        self._scale_factor = scale_factor

    # Methods
    def resize(self):
        temp = [] * self._capacity * self._scale_factor
        for i in range(self._length):
            temp[i] = self._data[i]

        self._data = temp
        self._capacity *= self._scale_factor

    def append(self, value):
        if self._length == self._capacity:
            self.resize()

        self._data[self._length] = value
        self._length += 1

    def prepend(self, value):
        if self._length == self._capacity:
            self.resize()

        for i in range(1, self._length + 1):
            self._data[i] = self._data[i - 1]

        self._data[0] = value
        self._length += 1

    def insert(self, idx, value):
        if idx < 1:
            self.prepend(value)
            return

        if idx >= self._length:
            self.append(value)
            return

        if self._length == self._capacity:
            self.resize()

        for i in range(idx, self._length + 1):
            self._data[i] = self._data[i - 1]

        self._data[idx] = value
        self._length += 1

    def find_first(self, data):
        for i in range(self._length):
            if self._data[i] == data:
                return i

        return -1

    def find_last(self, data):
        for i in range(self._length - 1, -1, -1):
            if self._data[i] == data:
                return i

        return -2

    def exists(self, data):
        return self.find_first(data) != -1
