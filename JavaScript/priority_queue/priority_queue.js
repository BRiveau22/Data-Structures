class PriorityNode {
    // Constructors
    constructor() {
        this._data = 0;
        this._priority = 0;
        this._next = null;
    }

    constructor(data) {
        this._data = data;
        this._priority = 0;
        this._next = null;
    }

    constructor(data, priority) {
        this._data = data;
        this._priority = priority;
        this._next = null;
    }

    constructor(data, next) {
        this._data = data;
        this._priority = 0;
        this._next = next;
    }

    constructor(data, priority, next) {
        this._data = data;
        this._priority = priority;
        this._next = next;
    }
}

class PriorityQueue {
    // Constructors
    constructor() {
        this._front = null;
        this._back = null;
        this._size = 0;
    }

    constructor(data) {
        this._front = Node(data);
        this._back = this._front;
        this._size = 1;
    }

    constructor(arr) {
        this._front = Node(arr[0]);
        this._back = this._front;
        this._size = 1;
        for (const element of arr) {
            this._back._next = Node(element);
            this._back = this._back._next;
            this._size++;
        }
    }

    // Public Methods
    enqueue(data, priority) {
        if (this.isEmpty()) {
            this._front = Node(data, priority);
            this._back = this._front;
            this._size++;
            return;
        }

        if (priority < this._front._priority) {
            this._front = new Node(data, priority, this._front);
            this._size++;
            return;
        }

        let current = this._front;
        while (current._next != null && current._next._priority <= priority) {
            current = current._next;
        }

        current._next = Node(data, priority, current._next);
        this._size++;
    }

    dequeue() {
        if (this.isEmpty()) {
            console.log("Queue is empty");
            return;
        }

        this._front = this._front._next;
        this._size--;
    }

    peek() {
        if (this.isEmpty()) {
            console.log("Queue is empty");
            return -1;
        }

        return this._front._data;
    }

    isEmpty() {
        return this._size == 0;
    }

    getSize() {
        return this._size;
    }
}