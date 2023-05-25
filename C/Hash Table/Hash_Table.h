#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <string.h>

typedef struct Hash_Table
{
    int *_table;
    int _mode;
    int _num_collisions;
    int _num_elements;
    int _table_size;
    double _a_value;
} Hash_Table;

// Constructors
Hash_Table *create(int mode);
Hash_Table *create_with_size(int mode, int size);

// Destructor
void destroy(Hash_Table *table);

// Private Methods
int _num_digits(Hash_Table *table);
int _div_hash(Hash_Table *table, int key);
int _mid_square_hash(Hash_Table *table, int key);
int _digit_folding_hash(Hash_Table *table, int key);
int _mult_hash(Hash_Table *table, int key, double a_value);
void _resize(Hash_Table *table);

// Public Methods
void insert(Hash_Table *table, int key);
#endif