class PriorityNode{
    constructor(){
        this.data = 0;
        this.priority = 0;
        this.next = null;
    }
    
    constructor(data){
        this.data = data;
        this.priority = 0;
        this.next = null;
    }

    constructor(data, priority){
        this.data = data;
        this.priority = priority;
        this.next = null;
    }

    constructor(data, next){
        this.data = data;
        this.priority = 0;
        this.next = next;
    }

    constructor(data, priority, next){
        this.data = data;
        this.priority = priority;
        this.next = next;
    }
}

class PriorityQueue{
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

    enqueue(data, priority){
        if(this.isEmpty()){
            this.front = new Node(data, priority);
            this.back = this.front;
            this.size++;
            return;
        }

        if(priority < this.front.priority){
            this.front = new Node(data, priority, this.front);
            this.size++;
            return;
        }

        let current = this.front;
        while(current.next != null && current.next.priority <= priority){
            current = current.next;
        }

        current.next = new Node(data, priority, current.next);
        this.size++;
    }

    dequeue(){
        if(this.isEmpty()){
            print("Queue is empty");
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