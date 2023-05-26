class Node {
    // Constructors
    constructor() {
        this._data = null;
        this._next = null;
    }

    constructor(value) {
        this._data = value;
        this._next = null;
    }

    constructor(value, next) {
        this._data = value;
        this._next = next;
    }
}

class Stack {
    // Constructors
    constructor() {
        this._top = null;
        this._size = 0;
    }

    constructor(value) {
        this._top = Node(value);
        this._size = 1;
    }

    constructor(list) {
        this._top = Node(list[list.length - 1]);
        let current = this._top;
        for (let i = 1; i < list.length; i++) {
            current._next = Node(list[i]);
            current = current._next;
        }
    }

    // Public Methods
    push(value) {
        this._top = Node(value, this._top);
        this._size++;
    }

    pop() {
        if (!this.isEmpty()) {
            let temp = this._top;
            this._top = this._top._next;
            this._size--;
            return temp._data;
        }

        return -1;
    }

    peek() {
        if (!this.isEmpty()) {
            return this._top._data;
        }

        return -1;
    }

    size() {
        return this._size;
    }

    isEmpty() {
        return this._size == 0;
    }
}