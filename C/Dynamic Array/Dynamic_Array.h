#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdbool.h>

typedef struct DynamicArray
{
    int *_data;
    int _length;
    int _capacity;
    double _scale_factor;
} DynamicArray;

// Constructors
DynamicArray *create_array();
DynamicArray *create_array_capacity(double scale_factor, int capacity);
DynamicArray *create_array_default_value(double scale_factor, int length, int default_value);

// Destructor
void destroy_array(DynamicArray *array);

// Methods
void resize(DynamicArray *array);
void append(DynamicArray *, int data);
void prepend(DynamicArray *, int data);
void insert(DynamicArray *, int data, int idx);
int find_first(DynamicArray *, int data);
int find_last(DynamicArray *, int data);
bool exists(DynamicArray *, int data);

#endif