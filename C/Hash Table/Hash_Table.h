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

#pragma region Constructors
Hash_Table *create_hash(int mode);
Hash_Table *create_hash_with_size(int mode, int size);
#pragma endregion

#pragma region Destructor
void destroy_hash(Hash_Table *table);
#pragma endregion

#pragma region Private Methods
int num_digits(Hash_Table *table);
int div_hash(Hash_Table *table, int key);
int mid_square_hash(Hash_Table *table, int key);
int digit_folding_hash(Hash_Table *table, int key);
int mult_hash(Hash_Table *table, int key, double a_value);
void resize(Hash_Table *table);
#pragma endregion

#pragma region Public Methods
void insert(Hash_Table *table, int key);
#pragma endregion
#endif