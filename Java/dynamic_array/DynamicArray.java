package dynamic_array;

import java.util.Arrays;

public class DynamicArray{
    private int length;
    private int capacity;
    private double scalingFactor;
    private int[] array;


    // Constructors
    public DynamicArray(){
        this.length = 0;
        this.capacity = 1;
        this.scalingFactor = 2;
        this.array = new int[this.capacity];
    }

    public DynamicArray(double scalingFactor, int capacity){
        this.length = 0;
        this.capacity = capacity;
        this.scalingFactor = scalingFactor;
        this.array = new int[this.capacity];
    }

    public DynamicArray(double scalingFactor, int length, int defaultValue){
        this.length = length;
        this.capacity = length;
        this.scalingFactor = scalingFactor;
        this.array = new int[this.capacity];
        Arrays.fill(this.array, defaultValue);
    }

    public DynamicArray(int[] array){
        this.length = array.length;
        this.capacity = array.length;
        this.scalingFactor = 2;
        this.array = array;
    }

    public DynamicArray(int[] array, double scalingFactor){
        this.length = array.length;
        this.capacity = array.length;
        this.scalingFactor = scalingFactor;
        this.array = array;
    }

    // Getters
    int getLength(){
        return this.length;
    }

    int getCapacity(){
        return this.capacity;
    }

    double getScalingFactor(){
        return this.scalingFactor;
    }

    int[] getArray(){
        return this.array;
    }

    // Setters
    void setLength(int length){
        this.length = length;
    }

    void setCapacity(int capacity){
        this.capacity = capacity;
    }

    void setScalingFactor(double scalingFactor){
        this.scalingFactor = scalingFactor;
    }

    // Methods
    void resize(){
        this.capacity *= this.scalingFactor;
        int[] newArray = new int[this.capacity];
        for (int i = 0; i < this.length; i++) {
            newArray[i] = this.array[i];
        }
        this.array = newArray;
    }

    void append(int value){
        if (this.length == this.capacity){
            this.resize();
        }
        this.array[this.length] = value;
        this.length++;
    }

    void prepend(int value){
        if(this.length == this.capacity){
            this.resize();
        }

        for(int i = 0; i < this.length; i++){
            this.array[i+1] = this.array[i];
        }
        this.array[0] = value;
        this.length++;
    }

    void insert (int value, int idx) {
        if (this.length == this.capacity){
            this.resize();
        }

        if (idx < 1){
            this.prepend(value);
            return;
        }
        else if (idx >= this.length){
            this.append(value);
            return;
        }
        
        for(int i = idx; i < this.length; i++){
            this.array[i+1] = this.array[i];
        }
        this.array[idx] = value;
    }

    int findFirst(int data){
        int idx = -1;
        for (int i = 0; i < this.length; i++) {
            if (this.array[i] == data){
                idx = i;
                break;
            }
        }

        return idx;
    }

    int findLast(int data){
        int idx = -1;
        for (int i = this.length - 1; i >= 0; i--) {
            if (this.array[i] == data){
                idx = i;
                break;
            }
        }

        return idx;
    }

    boolean exists(int data){
        return this.findFirst(data) != -1;
    }

    int getValue(int idx) {
        return this.array[idx];
    }
}