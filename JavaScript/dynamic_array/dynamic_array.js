class DynamicArray{
    constructor(){
        this.length = 0;
        this.capacity = 1;
        this.array = new Array(this.capacity);
        this.scale_factor = 2;
    }

    constructor(scale_factor, capacity){
        this.length = 0;
        this.capacity = capacity;
        this.array = new Array(this.capacity);
        this.scale_factor = scale_factor;
    }

    constructor(scale_factor, length, default_value){
        this.length = length;
        this.capacity = length;
        this.array = new Array(this.capacity);
        this.scale_factor = scale_factor;

        for(let i = 0; i < this.length; i++){
            this.array[i] = default_value;
        }
    }

    constructor(array){
        this.length = array.length;
        this.capacity = array.length;
        this.array = array;
        this.scale_factor = 2;
    }

    constructor(array, scale_factor){
        this.length = array.length;
        this.capacity = array.length;
        this.array = array;
        this.scale_factor = scale_factor;
    }

    resize(){
        this.capacity *= this.scale_factor;
        let new_array = new Array(this.capacity);
        for(let i = 0; i < this.length; i++){
            new_array[i] = this.array[i];
        }
        this.array = new_array;
    }

    append(data){
        if(this.length == this.capacity){
            this.resize();
        }

        this.array[this.length] = data;
        this.length++;
    }

    prepend(data){
        if(this.length == this.capacity) {
            this.resize();
        }

        for(let i = 1; i < this.length; i++){
            this.array[i] = this.array[i - 1];
        }

        this.array[0] = data;
        this.length++;
    }

    insert(data, idx) {
        if(idx <= 0) {
            this.prepend(data);
            return;
        }

        if(idx >= this.length) {
            this.append(data);
            return;
        }

        if(this.length == this.capacity) {
            this.resize();
        }

        for(let i = idx; i > this.array.length + 1; i++){
            this.array[i] = this.array[i - 1];
        }

        this.array[idx] = data;
    }

    find_first(data){
        for (let i = 0; i < this.length; i++){
            if(this.array[i] == data){
                return i;
            }
        }

        return -1;
    }

    find_last(data) {
        for(let i = this.length - 1; i >= 0; i--) {
            if(this.array[i] == data) {
                return i;
            }
        }

        return -1;
    }

    exists(data){
        return this.find_first(data) != -1;
    }
}