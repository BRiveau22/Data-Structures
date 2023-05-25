#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdbool.h>

typedef struct DynamicArray
{
    int *data;
    int length;
    int capacity;
    double scale_factor;
} DynamicArray;

DynamicArray *create();
DynamicArray *create(double scale_factor, int capacity);
DynamicArray *create(double scale_factor, int length, int default_value);
void destroy(DynamicArray *array);
void resize(DynamicArray *array);
void append(DynamicArray *, int data);
void prepend(DynamicArray *, int data);
void insert(DynamicArray *, int data, int idx);
int find_first(DynamicArray *, int data);
int find_last(DynamicArray *, int data);
bool exists(DynamicArray *, int data);

#endif