#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <string>
#include <cstring>
#include <iostream>

class DynamicArray {
private:
    unsigned int m_length;
    unsigned int m_capacity;
    double m_scaling_factor;
    int* m_data;
public:
    // Constructors
    DynamicArray();
    DynamicArray(double scaling_factor, unsigned int capacity);
    DynamicArray(double scaling_factor, unsigned int length, int default_value);
    DynamicArray(const DynamicArray& other);

    // Destructor
    ~DynamicArray();

    // Methods
    unsigned int get_length();
    unsigned int get_capacity();
    double get_scaling_factor();
    void set_scaling_factor(double value);
    std::string to_string();
    bool find_first_of(int value, unsigned int* index);
    bool find_last_of(int value, unsigned int* index);
    void append(int value);
    void prepend(int value);
    void remove_last();
    void remove_first();
    void clear();

    // overloading the [] operator for read/write access
    int& operator[](unsigned int index);

    // assignment operator
    DynamicArray& operator=(const DynamicArray& other);
};

#endif