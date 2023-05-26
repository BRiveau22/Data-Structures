class DynamicArray {
    // Constructors
    constructor() {
        this._length = 0;
        this._capacity = 1;
        this._array = int[this._capacity];
        this._scaleFactor = 2;
    }

    constructor(scaleFactor, capacity) {
        this._length = 0;
        this._capacity = capacity;
        this._array = int[this._capacity];
        this._scaleFactor = scaleFactor;
    }

    constructor(scaleFactor, length, defaultValue) {
        this._length = length;
        this._capacity = length;
        this._array = int[this._capacity];
        this._scaleFactor = scaleFactor;

        for (let i = 0; i < this._length; i++) {
            this._array[i] = defaultValue;
        }
    }

    constructor(array) {
        this._length = array.length;
        this._capacity = array.length;
        this._array = array;
        this._scaleFactor = 2;
    }

    constructor(array, scaleFactor) {
        this._length = array.length;
        this._capacity = array.length;
        this._array = array;
        this._scaleFactor = scaleFactor;
    }

    // Public Methods
    resize() {
        this._capacity *= this._scaleFactor;
        const newArray = int[this._capacity];
        for (let i = 0; i < this._length; i++) {
            newArray[i] = this._array[i];
        }
        this._array = newArray;
    }

    append(data) {
        if (this._length == this._capacity) {
            this.resize();
        }

        this._array[this._length] = data;
        this._length++;
    }

    prepend(data) {
        if (this._length == this._capacity) {
            this.resize();
        }

        for (let i = 1; i < this._length; i++) {
            this._array[i] = this._array[i - 1];
        }

        this._array[0] = data;
        this._length++;
    }

    insert(data, idx) {
        if (idx <= 0) {
            this.prepend(data);
            return;
        }

        if (idx >= this._length) {
            this.append(data);
            return;
        }

        if (this._length == this._capacity) {
            this.resize();
        }

        for (let i = idx; i < this._array.length + 1; i++) {
            this._array[i] = this._array[i - 1];
        }

        this._array[idx] = data;
    }

    findFirst(data) {
        for (let i = 0; i < this._length; i++) {
            if (this._array[i] == data) {
                return i;
            }
        }

        return -1;
    }

    findLast(data) {
        for (let i = this._length - 1; i >= 0; i--) {
            if (this._array[i] == data) {
                return i;
            }
        }

        return -1;
    }

    exists(data) {
        return this.findFirst(data) != -1;
    }
}