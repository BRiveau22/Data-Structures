#include "Dynamic_Array.h"

// Constructors
DynamicArray *create_array()
{
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->_data = 0;
    array->_length = 0;
    array->_capacity = 0;
    array->_scale_factor = 2.0;
    return array;
}

DynamicArray *create_array_capacity(double scale_factor, int capacity)
{
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->_data = (int *)malloc(sizeof(int) * capacity);
    array->_length = 0;
    array->_capacity = capacity;
    array->_scale_factor = scale_factor;
    return array;
}

DynamicArray *create_array_default_value(double scale_factor, int length, int default_value)
{
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->_data = (int *)malloc(sizeof(int) * length);
    array->_length = length;
    array->_capacity = length;
    array->_scale_factor = scale_factor;
    for (int i = 0; i < length; i++)
    {
        array->_data[i] = default_value;
    }
    return array;
}

// Destructor
void destroy_array(DynamicArray *array)
{
    free(array->_data);
    free(array);
}

// Methods
void resize(DynamicArray *array)
{
    int *new_data = (int *)malloc(sizeof(int) * array->_capacity * array->_scale_factor);
    for (int i = 0; i < array->_length; i++)
    {
        new_data[i] = array->_data[i];
    }
    free(array->_data);
    array->_data = new_data;
    array->_capacity *= array->_scale_factor;
}

void append(DynamicArray *array, int data)
{
    if (array->_length == array->_capacity)
    {
        resize(array);
    }
    array->_data[array->_length] = data;
    array->_length++;
}

void prepend(DynamicArray *array, int data)
{
    if (array->_length == array->_capacity)
    {
        resize(array);
    }

    for (int i = 1; i < array->_length; i++)
    {
        array->_data[i] = array->_data[i - 1];
    }
    array->_data[0] = data;
}

void insert(DynamicArray *array, int data, int idx)
{
    if (idx < 1)
    {
        prepend(array, data);
        return;
    }

    if (idx >= array->_length)
    {
        append(array, data);
        return;
    }

    if (array->_length == array->_capacity)
    {
        resize(array);
    }
    for (int i = idx; i < array->_length; i++)
    {
        array->_data[i + 1] = array->_data[i];
    }

    array->_data[idx] = data;
}

int find_first(DynamicArray *array, int data)
{
    for (int i = 0; i < array->_length; i++)
    {
        if (array->_data[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int find_last(DynamicArray *array, int data)
{
    for (int i = array->_length - 1; i >= 0; i--)
    {
        if (array->_data[i] == data)
        {
            return i;
        }
    }
    return -1;
}

bool exists(DynamicArray *array, int data)
{
    if (find_first(array, data) != -1)
    {
        return true;
    }

    return false;
}