class Node{
    constructor(){
        this.data = 0;
        this.next = null;
    }

    constructor(data){
        this.data = data;
        this.next = null;
    }

    constructor (data, next) {
        this.data = data;
        this.next = next;
    }
}

class Queue{
    constructor(){
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    constructor(data){
        this.front = new Node(data);
        this.back = this.front;
        this.size = 1;
    }

    constructor(arr){
        this.front = new Node(arr[0]);
        this.back = this.front;
        this.size = 1;
        for(let i = 0; i < arr.length; i++){
            this.back.next = new Node(arr[i]);
            this.back = this.back.next;
            this.size++;
        }
    }

    enqueue(data){
        if(this.isEmpty()){
            this.front = new Node(data);
            this.back = this.front;
            this.size++;
            return;
        }

        this.back.next = new Node(data);
        this.back = back.next;
        this.size++;
    }

    dequeue(){
        if(this.isEmpty()){
            print("Queue is empty");
            return;
        }

        if(this.size == 1){
            this.front = null;
            this.back = null;
            this.size--;
            return;
        }

        this.front = this.front.next;
        this.size--;
    }

    peek(){
        if(this.isEmpty()){
            print("Queue is empty");
            return -1;
        }

        return this.front.data;
    }

    isEmpty(){
        return this.size == 0;
    }

    getSize(){
        return this.size;
    }
}