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

#pragma region Constructors
DynamicArray *create_array();
DynamicArray *create_array_capacity(double scale_factor, int capacity);
DynamicArray *create_array_default_value(double scale_factor, int length, int default_value);
#pragma endregion

#pragma region Destructor
void destroy_array(DynamicArray *array);
#pragma endregion

#pragma region Methods
void resize(DynamicArray *array);
void append(DynamicArray *array, int data);
void prepend(DynamicArray *array, int data);
void insert(DynamicArray *array, int data, int idx);
int find_first(DynamicArray *array, int data);
int find_last(DynamicArray *array, int data);
bool exists(DynamicArray *array, int data);
#pragma endregion
#endif