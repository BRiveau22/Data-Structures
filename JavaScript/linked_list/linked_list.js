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

class linked_list{
    constructor(){
        this.head = null;
        this.size = 0;
    }

    append(data){
        if(this.head == null){
            this.head = new Node(data);
            this.size++;
            return;
        }

        let current = this.head;
        while(current.next != null){
            current = current.next;
        }

        current.next = new Node(data);
        this.size++;
    }

    prepend(data){
        if(this.head == null){
            this.head = new Node(data);
            this.size++;
            return;
        }

        let new_head = new Node(data);
        new_head.next = this.head;
        this.head = new_head;
        this.size++;
    }

    insert(data, index){
        if(index < 1){
            this.prepend(data);
            return;
        }
        else if (index >= this.size){
            this.append(data);
            return;
        }
        
        let current = this.head;
        for (let i = 0; i < index - 1; i++){
            current = current.next;
        }
        let new_node = new Node(data);
        new_node.next = current.next;
        current.next = new_node;
        this.size++;
    }

    remove(data){
        if(this.head == null){
            return;
        }

        if(this.head.data == data){
            this.head = this.head.next;
            this.size--;
            return;
        }

        let current = this.head;
        while(current.next != null){
            if(current.next.data == data){
                current.next = current.next.next;
                this.size--;
                return;
            }
            current = current.next;
        }
    }

    contains(data){
        let current = this.head;
        while(current != null){
            if(current.data == data){
                return true;
            }
            current = current.next;
        }
    }

    print(){
        let current = this.head;
        while(current != null){
            console.log(current.data);
            current = current.next;
        }
    }
}