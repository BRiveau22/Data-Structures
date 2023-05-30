import random


class HashTable:
    # Constructors
    def __init__(self, mode):
        self._mode = mode
        self._num_collisions = 0
        self._num_elements = 0
        self._table_size = 1
        self._table = [None for i in range(self._table_size)]

        if mode == 3:
            self._a_value = random.random()

    def __init__(self, mode, table_size):
        self._mode = mode
        self._num_collisions = 0
        self._num_elements = 0
        self._table_size = table_size
        self._table = [None for i in range(self._table_size)]

        if mode == 3:
            self._a_value = random.random()

    # Private Methods
    def num_digits(self):
        temp_size = self._table_size - 1
        r = 0
        while temp_size > 0:
            temp_size /= 10
            r += 1

        return r

    def div_hash(self, key):
        idx = key % self._table_size
        if self._table[idx] != 0:
            self._num_collisions += 1
            idx = self.div_hash(key + 1)

        return idx

    def mid_square_hash(self, key):
        r = self.num_digits()

        square = (key * key).ToString()
        idx = square.Substring((square.Length / 2) - (r / 2), r).ToInt()

        if self._table[idx] != 0:
            self._num_collisions += 1
            idx = self.mid_square_hash(key + 1)

        return idx

    def digit_folding_hash(self, key):
        r = self.num_digits()

        key_str = key.ToString()
        while key_str.Length > 0:
            if r > key_str.Length:
                r = key_str.Length

            idx += key_str.Substring(0, r).ToInt()
            key_str = key_str.Substring(r)

        if self._table[idx] != 0:
            self._num_collisions += 1
            idx = self.digit_folding_hash(key + 1)

        return idx

    def mult_hash(self, key, a):
        idx = (int)(self._table_size * ((key * a) % 1))

        if self._table[idx] != 0:
            self._num_collisions += 1
            idx = self.mult_hash(key + 1, a)

        return idx

    def resize(self):
        new_table = HashTable(self._mode, self._table_size * 2)
        for i in range(self._table_size):
            if self._table[i] != 0:
                new_table.insert(self._table[i])

        return new_table

    # Public Methods
    def insert(self, key):
        if self._num_elements / self._table_size > 0.7:
            self = self.resize()

        if self._mode == 0:
            idx = self.div_hash(key)
        elif self._mode == 1:
            idx = self.mid_square_hash(key)
        elif self._mode == 2:
            idx = self.digit_folding_hash(key)
        elif self._mode == 3:
            idx = self.mult_hash(key, self._a_value)
        else:
            idx = self.div_hash(key)

        self._table[idx] = key
        self._num_elements += 1
