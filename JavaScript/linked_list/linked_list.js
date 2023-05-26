class Node {
    // Constructors
    constructor() {
        this._data = 0;
        this._next = null;
    }

    constructor(data) {
        this._data = data;
        this._next = null;
    }

    constructor(data, next) {
        this._data = data;
        this._next = next;
    }
}

class LinkedList {
    // Constructors
    constructor() {
        this._head = null;
        this._size = 0;
    }

    // Public Methods
    append(data) {
        if (this._head == null) {
            this._head = Node(data);
            this._size++;
            return;
        }

        let current = this._head;
        while (current._next != null) {
            current = current._next;
        }

        current._next = Node(data);
        this._size++;
    }

    prepend(data) {
        if (this._head == null) {
            this._head = Node(data);
            this._size++;
            return;
        }

        const newHead = Node(data);
        newHead._next = this._head;
        this._head = newHead;
        this._size++;
    }

    insert(data, index) {
        if (index < 1) {
            this.prepend(data);
            return;
        }
        else if (index >= this._size) {
            this.append(data);
            return;
        }

        let current = this._head;
        for (let i = 0; i < index - 1; i++) {
            current = current._next;
        }

        let newNode = Node(data);
        newNode._next = current._next;
        current._next = newNode;
        this._size++;
    }

    remove(data) {
        if (this._head == null) {
            return;
        }

        if (this._head._data == data) {
            this._head = this._head._next;
            this._size--;
            return;
        }

        let current = this._head;
        while (current._next != null) {
            if (current._next._data == data) {
                current._next = current._next._next;
                this._size--;
                return;
            }
            current = current._next;
        }
    }

    contains(data) {
        let current = this._head;
        while (current != null) {
            if (current._data == data) {
                return true;
            }
            current = current._next;
        }
    }

    print() {
        let current = this._head;
        while (current != null) {
            console.log(current._data);
            current = current._next;
        }
    }
}