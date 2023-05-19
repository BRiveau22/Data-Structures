package hash_table;

public class HashTable{
    private int[] table;
    private int mode;
    private int numCollisions;
    private int numElements;
    private int tableSize;
    private double aValue;

    // Constructors
    public HashTable(int mode){
        this.mode = mode;
        this.numCollisions = 0;
        this.numElements = 0;
        this.tableSize = 1;
        this.table = new int[this.tableSize];

        if(mode == 3){
            this.aValue = Math.random();
        }
    }


    public HashTable(int mode, int tableSize){
        this.mode = mode;
        this.numCollisions = 0;
        this.numElements = 0;
        this.tableSize = tableSize;
        this.table = new int[this.tableSize];

        if(mode == 3){
            this.aValue = Math.random();
        }
    }


    // Private Methods
    private int numDigits(){
        int tempSize = this.tableSize - 1;
        int r = 0;
        while (tempSize > 0){
            tempSize /= 10;
            r++;
        }

        return r;
    }


    private int divHash(int key){
        int idx = key % this.tableSize;
        if(this.table[idx] != 0){
            this.numCollisions++;
            idx = this.divHash(key + 1);
        }
        
        return idx;
    }


    private int midSquareHash(int key){
        int idx = 0;
        int r = this.numDigits();

        String square = String.valueOf(key * key);
        idx = Integer.parseInt(square.substring((square.length() / 2) - (r / 2), r));

        if(this.table[idx] != 0){
            this.numCollisions++;
            idx = this.midSquareHash(key + 1);
        }

        return idx;
    }


    private int digitFoldingHash(int key){
        int idx = 0;
        int r = this.numDigits();

        String keyStr = String.valueOf(key);
        while(keyStr.length() > 0){
            if(r > keyStr.length()){
                r = keyStr.length();
            }

            idx += Integer.parseInt(keyStr.substring(0, r));
            keyStr = keyStr.substring(r);
        }

        if(this.table[idx] != 0){
            this.numCollisions++;
            idx = this.digitFoldingHash(key + 1);
        }

        return idx;
    }


    private int multHash(int key, double a){
        int idx = (int)(this.tableSize * ((key * a) % 1));

        if(this.table[idx] != 0){
            this.numCollisions++;
            idx = this.multHash(key + 1, a);
        }

        return idx;
    }


    private void resize(){
        HashTable newTable = new HashTable(this.mode, this.tableSize * 2);
        for(int i = 0; i < this.tableSize; i++){
            if(this.table[i] != 0){
                newTable.insert(this.table[i]);
            }
        }

        this.table = newTable.table;
        this.tableSize = newTable.tableSize;
        this.numCollisions = newTable.numCollisions;
        this.numElements = newTable.numElements;
        this.aValue = newTable.aValue;
    }


    // Public Methods
    public void insert(int key){
        if((double)this.numElements / (double)this.tableSize > 0.7){
            this.resize();
        }

        int idx;
        switch(this.mode){
            case 0:
                idx = this.divHash(key);
                break;
            case 1:
                idx = this.midSquareHash(key);
                break;
            case 2:
                idx = this.digitFoldingHash(key);
                break;
            case 3:
                idx = this.multHash(key, this.aValue);
                break;
            default:
                idx = this.divHash(key);
                break;
        }

        this.table[idx] = key;
        this.numElements++;
    }
}