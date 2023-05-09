public class Hash_Table{
    private int[] _table;
    private int _mode;
    private int _num_collisions;
    private int _num_elements;
    private int _table_size;
    private double _a_value;

    // Constructors
    public Hash_Table(int mode){
        this._mode = mode;
        this._num_collisions = 0;
        this._num_elements = 0;
        this._table_size = 1;
        this._table = new int[this._table_size];

        if(mode == 3){
            var rand = new Random();
            this._a_value = new decimal(rand.NextDouble());
        }
    }


    public Hash_Table(int mode, int table_size){
        this._mode = mode;
        this._num_collisions = 0;
        this._num_elements = 0;
        this._table_size = table_size;
        this._table = new int[this._table_size];
        
        if(mode == 3){
            var rand = new Random();
            this._a_value = new decimal(rand.NextDouble());
        }
    }


    // Private Methods
    private int num_digits(){
        int temp_size = this._table_size - 1;
        int r = 0;
        while (temp_size > 0){
            temp_size /= 10;
            r++;
        }

        return r;
    }   


    private int div_hash(int key){
        int idx = key % this._table_size;
        if(this._table[idx] != 0){
            this._num_collisions++;
            idx = this.div_hash(key + 1);
        }
        
        return idx;
    }


    private int mid_square_hash(int key){
        int idx;
        int r = this.num_digits();

        string square = (key * key).ToString();
        idx = square.Substring((square.Length / 2) - (r / 2), r).ToInt();

        if(this._table[idx] != 0){
            this._num_collisions++;
            idx = this.mid_square_hash(key + 1);
        }

        return idx;
    }


    private int digit_folding_hash(int key){
        int idx;
        int r = this.num_digits();

        string key_str = key.ToString();
        while(key_str.Length > 0){
            if(r > key_str.Length){
                r = key_str.Length;
            }

            idx += key_str.Substring(0, r).ToInt();
            key_str = key_str.Substring(r);
        }

        if(this._table[idx] != 0){
            this._num_collisions++;
            idx = this.digit_folding_hash(key + 1);
        }

        return idx;
    }


    private int mult_hash(int key, double a){
        int idx = (int)(this._table_size * ((key * a) % 1));

        if(this._table[idx] != 0){
            this._num_collisions++;
            idx = this.mult_hash(key + 1, a);
        }

        return idx;
    }


    private void resize(){
        Hash_Table new_table = new Hash_Table(this._mode, this._table_size * 2);
        for(int i = 0; i < this._table_size; i++){
            if(this._table[i] != 0){
                new_table.insert(this._table[i]);
            }
        }

        this = new_table;
    }


    // Public Methods
    public void insert(int key){
        if((double)this._num_elements / (double)this._table_size > 0.7){
            this.resize();
        }

        int idx;
        switch(this._mode){
            case 0:
                idx = this.div_hash(key);
                break;
            case 1:
                idx = this.mid_square_hash(key);
                break;
            case 2:
                idx = this.digit_folding_hash(key);
                break;
            case 3:
                idx = this.mult_hash(key, this._a_value);
                break;
            default:
                idx = this.div_hash(key);
                break;
        }

        this._table[idx] = key;
        this._num_elements++;
    }
}