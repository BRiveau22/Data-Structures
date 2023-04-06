#include "Dynamic_Array.h"
#include <cstring>
#include <iostream>

DynamicArray::DynamicArray()
    : m_length(0), m_capacity(0), m_scaling_factor(2.0), m_data(nullptr) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    this->m_data = new int[capacity];
    this->m_length = 0;
    this->m_capacity = capacity;
    this->m_scaling_factor = scaling_factor;
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    this->m_data = new int[length];
    this->m_length = length;
    this->m_capacity = length;
    this->m_scaling_factor = scaling_factor;
    for (int i = 0; i < m_length; i++) {
        m_data[i] = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other;
}

// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::to_string() {
    std::string str("");

    for (int i = 0; i < m_length; i++) {
        if (i == m_length - 1) {
            str += std::to_string(m_data[i]);
        }
        else {
            str += std::to_string(m_data[i]) + " ";
        }
    }

    return str;
}

void DynamicArray::append(int value) {
    //Increases the length and capacity of the array as necessary
    if (m_length == m_capacity) {
        m_capacity *= m_scaling_factor;

        //Increases the capacity of m_data by 1
        auto new_m_data = new int[m_capacity];
        for (int i = 0; i < m_length; i++) {
            new_m_data[i] = m_data[i];
        }
        this->~DynamicArray();
        m_data = new_m_data;
    }

    //Appends the input value to the array
    m_data[m_length] = value;
    m_length++;
}

void DynamicArray::prepend(int value) {
    //Increases the length and capacity of the array as necessary
    if (m_length == m_capacity) {
        m_capacity *= m_scaling_factor;

        //Increases the capacity of m_data by 1
        auto new_m_data = new int[m_capacity];
        for (int i = 0; i < m_length; i++) {
            new_m_data[i + 1] = m_data[i];
        }
        this->~DynamicArray();
        m_data = new_m_data;
    }
    else {
        for (int i = m_length; i > 0; i--) {
            m_data[i] = m_data[i - 1];
        }
    }

    m_data[0] = value;
    m_length++;
}

bool DynamicArray::find_first_of(int value, unsigned int* index) {
    bool found = false;
    for (int i = 0; i < m_length; i++) {
        if (m_data[i] == value) {
            found = true;
            *index = i;
            break;
        }
    }
    return found;
}

bool DynamicArray::find_last_of(int value, unsigned int* index) {
    bool found = false;
    for (int i = m_length - 1; i >= 0; i--) {
        if (m_data[i] == value) {
            found = true;
            *index = i;
            break;
        }
    }
    return found;
}

void DynamicArray::remove_last() {
    if (m_length > 0) {
        auto new_m_data = new int[m_length - 1];
        for (int i = 0; i < m_length - 1; i++) {
            new_m_data[i] = m_data[i];
        }
        this->~DynamicArray();
        m_data = new_m_data;
        m_length -= 1;
    }
}

void DynamicArray::remove_first() {
    if (m_length > 0) {
        auto new_m_data = new int[m_length - 1];
        for (int i = 1; i < m_length; i++) {
            new_m_data[i - 1] = m_data[i];
        }
        this->~DynamicArray();
        m_data = new_m_data;
        m_length -= 1;
    }
}

void DynamicArray::clear() {
    this->~DynamicArray();
    this->m_data = nullptr;
    m_length = 0;
    m_capacity = 0;
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);

    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this);
}