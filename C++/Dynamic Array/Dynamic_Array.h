#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <string>
#include <cstring>
#include <iostream>

class DynamicArray
{
private:
#pragma region Private Properties
    unsigned int _length;
    unsigned int _capacity;
    double _scaling_factor;
    int *_data;
#pragma endregion

public:
#pragma region Constructors
    DynamicArray();
    DynamicArray(double scaling_factor, unsigned int capacity);
    DynamicArray(double scaling_factor, unsigned int length, int default_value);
    DynamicArray(const DynamicArray &other);
#pragma endregion

#pragma region Destructor
    ~DynamicArray();
#pragma endregion

#pragma region Public Methods
    unsigned int get_length();
    unsigned int get_capacity();
    double get_scaling_factor();
    void set_scaling_factor(double value);
    std::string to_string();
    bool find_first_of(int value, unsigned int *index);
    bool find_last_of(int value, unsigned int *index);
    void append(int value);
    void prepend(int value);
    void remove_last();
    void remove_first();
    void clear();
#pragma endregion

#pragma region Operator Overloads
    // overloading the [] operator for read/write access
    int &operator[](unsigned int index);

    // assignment operator
    DynamicArray &operator=(const DynamicArray &other);
#pragma endregion
};

#endif