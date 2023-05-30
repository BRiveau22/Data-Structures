#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <string>
#include <vector>

class Hash_Table
{
private:
#pragma region Private Properties
    std::vector<int> _table;
    int _mode;
    int _num_collisions;
    int _num_elements;
    int _table_size;
    double _a_value;
#pragma endregion

#pragma region Private Methods
    int num_digits();
    int div_hash(int key);
    int mid_square_hash(int key);
    int digit_folding_hash(int key);
    int mult_hash(int key, double a);
    void resize_table();
#pragma endregion

public:
#pragma region Constructors
    Hash_Table(int mode);
    Hash_Table(int mode, int table_size);
#pragma endregion

#pragma region Destructor
    ~Hash_Table();
#pragma endregion

#pragma region Public Methods
    void insert(int key);
#pragma endregion
};

#endif