class Node{
    // Constructors
    constructor(){
        this.data = null;
        this.next = null;
    }

    constructor(value){
        this.data = value;
        this.next = null;
    }

    constructor(value, next){
        this.data = value;
        this.next = next;
    }
}

class Stack{
    // Constructors
    constructor(){
        this.top = null;
        this.size = 0;
    }

    constructor(value){
        this.top = new Node(value);
        this.size = 1;
    }

    constructor(list){
        this.top = new Node(list[list.size - 1]);
        current = this.top;
        for (let i = 1; i < list.size; i++){
            current.next = new Node(list[i]);
            current = current.next;
        }
    }

    // Methods
    push(value){
        this.top = new Node(value, this.top);
        this.size++;
    }

    pop(){
        if(!this.isEmpty()){
            let temp = this.top;
            this.top = this.top.next;
            this.size--;
            return temp.data;
        }

        return null;
    }

    top(){
        if(!this.isEmpty()){
            return this.top.data;
        }

        return null;
    }

    size(){
        return this.size;
    }

    isEmpty(){
        return this.size == 0;
    }
}