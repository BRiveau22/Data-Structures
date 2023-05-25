#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <string>
#include <vector>

class Hash_Table
{
private:
    std::vector<int> _table;
    int _mode;
    int _num_collisions;
    int _num_elements;
    int _table_size;
    double _a_value;

    // Methods
    int _num_digits();
    int _div_hash(int key);
    int _mid_square_hash(int key);
    int _digit_folding_hash(int key);
    int _mult_hash(int key, double a);
    void _resize_table();

public:
    // Constructors
    Hash_Table(int mode);
    Hash_Table(int mode, int table_size);
    ~Hash_Table();

    // Methods
    void insert(int key);
};

#endif