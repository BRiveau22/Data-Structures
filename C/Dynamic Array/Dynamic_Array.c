#include "Dynamic_Array.h"

DynamicArray* create() {
    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    array->data = 0;
    array->length = 0;
    array->capacity = 0;
    array->scale_factor = 2.0;
    return array;
}

DynamicArray* create(double scale_factor, int capacity) {
    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    array->data = (int*)malloc(sizeof(int) * capacity);
    array->length = 0;
    array->capacity = capacity;
    array->scale_factor = scale_factor;
    return array;
}

DynamicArray* create(double scale_factor, int length, int default_value) {
    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    array->data = (int*)malloc(sizeof(int) * length);
    array->length = length;
    array->capacity = length;
    array->scale_factor = scale_factor;
    for(int i = 0; i < length; i++) {
        array->data[i] = default_value;
    }
    return array;
}

void destroy(DynamicArray* array) {
    free(array->data);
    free(array);
}

void resize(DynamicArray* array) {
    int* new_data = (int*)malloc(sizeof(int) * array->capacity * array->scale_factor);
    for(int i = 0; i < array->length; i++) {
        new_data[i] = array->data[i];
    }
    free(array->data);
    array->data = new_data;
    array->capacity *= array->scale_factor;
}

void append(DynamicArray* array, int data) {
    if(array->length == array->capacity) {
        resize(array);
    }
    array->data[array->length] = data;
    array->length++;
}

void prepend(DynamicArray* array, int data) {
    if(array->length == array->capacity) {
        resize(array);
    }

    for(int i = 1; i < array->length; i++){
        array->data[i] = array->data[i - 1];
    }
    array->data[0] = data;
}

void insert(DynamicArray* array, int data, int idx) {
    if(idx < 1) {
        prepend(array, data);
        return;
    }
    
    if(idx >= array->length) {
        append(array, data);
        return;
    }

    if(array->length == array->capacity) {
        resize(array);
    }
    for(int i = idx; i < array->length; i++) {
        array->data[i + 1] = array->data[i];
    }

    array->data[idx] = data;
}

int find_first(DynamicArray* array, int data) {
    for(int i = 0; i < array->length; i++) {
        if(array->data[i] == data) {
            return i;
        }
    }
    return -1;
}

int find_last(DynamicArray* array, int data) {
    for(int i = array->length - 1; i >= 0; i--){
        if(array->data[i] == data) {
            return i;
        }
    }
    return -1;
}

bool exists(DynamicArray* array, int data) {
    if(find_first(array, data) != -1) {
        return true;
    }

    return false;
}