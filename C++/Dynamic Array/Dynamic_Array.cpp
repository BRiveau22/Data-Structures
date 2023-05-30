#include "Dynamic_Array.h"

#pragma region Constructors
DynamicArray::DynamicArray()
    : _length(0), _capacity(0), _scaling_factor(2.0), _data(nullptr)
{
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity)
{
    this->_data = new int[capacity];
    this->_length = 0;
    this->_capacity = capacity;
    this->_scaling_factor = scaling_factor;
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value)
{
    this->_data = new int[length];
    this->_length = length;
    this->_capacity = length;
    this->_scaling_factor = scaling_factor;
    for (int i = 0; i < _length; i++)
    {
        _data[i] = default_value;
    }
}

// Copy Constructor
DynamicArray::DynamicArray(const DynamicArray &other)
{
    // use the assignment operator
    (*this) = other;
}
#pragma endregion

#pragma region Destructor
DynamicArray::~DynamicArray()
{
    delete[] _data;
}
#pragma endregion

#pragma region Public Methods
unsigned int DynamicArray::get_length()
{
    return _length;
}

unsigned int DynamicArray::get_capacity()
{
    return _capacity;
}

double DynamicArray::get_scaling_factor()
{
    return _scaling_factor;
}

void DynamicArray::set_scaling_factor(double value)
{
    _scaling_factor = value;
}

std::string DynamicArray::to_string()
{
    std::string str("");

    for (int i = 0; i < _length; i++)
    {
        if (i == _length - 1)
        {
            str += std::to_string(_data[i]);
        }
        else
        {
            str += std::to_string(_data[i]) + " ";
        }
    }

    return str;
}

void DynamicArray::append(int value)
{
    if (_length == _capacity)
    {
        _capacity *= _scaling_factor;

        auto new_m_data = new int[_capacity];
        for (int i = 0; i < _length; i++)
        {
            new_m_data[i] = _data[i];
        }
        this->~DynamicArray();
        _data = new_m_data;
    }

    _data[_length] = value;
    _length++;
}

void DynamicArray::prepend(int value)
{
    if (_length == _capacity)
    {
        _capacity *= _scaling_factor;

        auto new_m_data = new int[_capacity];
        for (int i = 0; i < _length; i++)
        {
            new_m_data[i + 1] = _data[i];
        }
        this->~DynamicArray();
        _data = new_m_data;
    }
    else
    {
        for (int i = _length; i > 0; i--)
        {
            _data[i] = _data[i - 1];
        }
    }

    _data[0] = value;
    _length++;
}

bool DynamicArray::find_first_of(int value, unsigned int *index)
{
    bool found = false;
    for (int i = 0; i < _length; i++)
    {
        if (_data[i] == value)
        {
            found = true;
            *index = i;
            break;
        }
    }
    return found;
}

bool DynamicArray::find_last_of(int value, unsigned int *index)
{
    bool found = false;
    for (int i = _length - 1; i >= 0; i--)
    {
        if (_data[i] == value)
        {
            found = true;
            *index = i;
            break;
        }
    }
    return found;
}

void DynamicArray::remove_last()
{
    if (_length > 0)
    {
        auto new_m_data = new int[_length - 1];
        for (int i = 0; i < _length - 1; i++)
        {
            new_m_data[i] = _data[i];
        }
        this->~DynamicArray();
        _data = new_m_data;
        _length -= 1;
    }
}

void DynamicArray::remove_first()
{
    if (_length > 0)
    {
        auto new_m_data = new int[_length - 1];
        for (int i = 1; i < _length; i++)
        {
            new_m_data[i - 1] = _data[i];
        }
        this->~DynamicArray();
        _data = new_m_data;
        _length -= 1;
    }
}

void DynamicArray::clear()
{
    this->~DynamicArray();
    this->_data = nullptr;
    _length = 0;
    _capacity = 0;
}
#pragma endregion

#pragma region Operator Overloads
int &DynamicArray::operator[](unsigned int index)
{
    return _data[index];
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other)
{
    _length = other._length;
    _capacity = other._capacity;
    _scaling_factor = other._scaling_factor;
    _data = new int[_capacity];
    std::memcpy(_data, other._data, sizeof(int) * _length);

    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this);
}
#pragma endregion