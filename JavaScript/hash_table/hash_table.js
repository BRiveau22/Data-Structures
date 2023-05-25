class HashTable {
    // Constructors
    constructor(mode) {
        this._mode = mode;
        this._numCollisions = 0;
        this._numElements = 0;
        this._tableSize = 1;
        this._table = new int[this.tableSize];

        if (mode == 3) {
            // Assign a_value to a random double between 0 and 1
        }
    }

    constructor(mode, tableSize) {
        this._mode = mode;
        this._numCollisions = 0;
        this._numElements = 0;
        this._tableSize = tableSize;
        this._table = new int[this.tableSize];

        if (mode == 3) {
            // Assign a_value to a random double between 0 and 1
        }
    }

    // Private Methods
    _numDigits() {
        let tempSize = this._tableSize - 1;
        let r = 0;
        while (tempSize > 0) {
            tempSize /= 10;
            r++;
        }

        return r;
    }


    _divHash(key) {
        let idx = key % this._tableSize;
        if (this._table[idx] != 0) {
            this._numCollisions++;
            idx = this._divHash(key + 1);
        }

        return idx;
    }


    _midSquareHash(key) {
        let r = this._numDigits();

        const square = (key * key).toString();
        let idx = Number(square.substring((square.length / 2) - (r / 2), r));

        if (this._table[idx] != 0) {
            this._numCollisions++;
            idx = this._midSquareHash(key + 1);
        }

        return idx;
    }


    _digitFoldingHash(key) {
        let idx = 0;
        let r = this.num_digits();

        let keyStr = key.toString();
        while (keyStr.length > 0) {
            if (r > keyStr.length) {
                r = keyStr.length;
            }

            idx += Number(keyStr.substring(0, r));
            keyStr = keyStr.substring(r);
        }

        if (this._table[idx] != 0) {
            this._numCollisions++;
            idx = this._digitFoldingHash(key + 1);
        }

        return idx;
    }


    _multHash(key, a) {
        let idx = (int)(this._tableSize * ((key * a) % 1));

        if (this._table[idx] != 0) {
            this._numCollisions++;
            idx = this._multHash(key + 1, a);
        }

        return idx;
    }


    _resize() {
        const new_table = new HashTable(this._mode, this._tableSize * 2);
        for (let i = 0; i < this._tableSize; i++) {
            if (this._table[i] != 0) {
                new_table.insert(this._table[i]);
            }
        }

        this = new_table;
    }

    // Public Methods
    insert(key) {
        if (this._numElements / this._tableSize > 0.7) {
            this._resize();
        }

        let idx = 0;
        switch (this._mode) {
            case 0:
                idx = this._divHash(key);
                break;
            case 1:
                idx = this._midSquareHash(key);
                break;
            case 2:
                idx = this._digitFoldingHash(key);
                break;
            case 3:
                idx = this._multHash(key, this._a);
                break;
            default:
                idx = this._divHash(key);
                break;
        }

        this._table[idx] = key;
        this._num_elements++;
    }
}