#include "Hash_Table.h"

// Constructors
Hash_Table *create(int mode)
{
    Hash_Table *hash_table = (Hash_Table *)malloc(sizeof(Hash_Table));
    hash_table->_table = 0;
    hash_table->_mode = mode;
    hash_table->_num_collisions = 0;
    hash_table->_num_elements = 0;
    hash_table->_table_size = 0;
    hash_table->_a_value = 0;

    return hash_table;
}

Hash_Table *create_with_size(int mode, int size)
{
    Hash_Table *hash_table = (Hash_Table *)malloc(sizeof(Hash_Table));
    hash_table->_table = (int *)malloc(sizeof(int) * size);
    hash_table->_mode = mode;
    hash_table->_num_collisions = 0;
    hash_table->_num_elements = 0;
    hash_table->_table_size = size;
    hash_table->_a_value = 0;

    return hash_table;
}

// Destructor
void destroy(Hash_Table hash_table)
{
    free(hash_table._table);
    free(&hash_table);
}

// Private Methods
int _num_digits(Hash_Table *hash_table)
{
    int temp_size = hash_table->_table_size - 1;
    int r = 0;
    while (temp_size > 0)
    {
        temp_size /= 10;
        r++;
    }

    return r;
}

int _div_hash(Hash_Table *hash_table, int key)
{
    int idx = key % hash_table->_table_size;
    if (hash_table->_table[idx] != 0)
    {
        hash_table->_num_collisions++;
        idx = _div_hash(hash_table, key + 1);
    }

    return idx;
}

int _mid_square_hash(Hash_Table *hash_table, int key)
{
    int idx;
    int r = _num_digits(hash_table);

    char square[] = key * key;
    strncpy(square, square + (strlen(square) / 2) - (r / 2), r);
    idx = atoi(square);

    if (hash_table->_table[idx] != 0)
    {
        hash_table->_num_collisions++;
        idx = _mid_square_hash(hash_table, key + 1);
    }

    return idx;
}

int _digit_folding_hash(Hash_Table *hash_table, int key)
{
    int idx;
    int r = _num_digits(hash_table);

    char key_str[] = key;
    while (key_str > 0)
    {
        if (r > strlen(key_str))
        {
            r = strlen(key_str);
        }

        strncpy(key_str, key_str, r);
        idx += atoi(key_str);
        strncpy(key_str, key_str, r);
    }

    if (hash_table->_table[idx] != 0)
    {
        hash_table->_num_collisions++;
        idx = _digit_folding_hash(hash_table, key + 1);
    }

    return idx;
}

int _mult_hash(Hash_Table *hash_table, int key, double a_value)
{
    int random = (key * a_value) + 0.5;
    int idx = hash_table->_table_size * random;

    if (hash_table->_table[idx] != 0)
    {
        hash_table->_num_collisions++;
        idx = _mult_hash(hash_table, key + 1, a_value);
    }

    return idx;
}

void _resize(Hash_Table *hash_table)
{
    Hash_Table *new_table = create_with_size(hash_table->_mode, hash_table->_table_size * 2);
    for (int i = 0; i < hash_table->_table_size; i++)
    {
        if (hash_table->_table[i] != 0)
        {
            insert(new_table, hash_table->_table[i]);
        }
    }

    hash_table = new_table;
}

// Public Methods
void insert(Hash_Table *hash_table, int key)
{
    if ((double)hash_table->_num_elements / (double)hash_table->_table_size > 0.7)
    {
        _resize(hash_table);
    }

    int idx;
    switch (hash_table->_mode)
    {
    case 0:
        idx = _div_hash(hash_table, key);
        break;
    case 1:
        idx = _mid_square_hash(hash_table, key);
        break;
    case 2:
        idx = _digit_folding_hash(hash_table, key);
        break;
    case 3:
        idx = _mult_hash(hash_table, key, hash_table->_a_value);
        break;
    default:
        idx = _div_hash(hash_table, key);
        break;
    }

    hash_table->_table[idx] = key;
    hash_table->_num_elements++;
}