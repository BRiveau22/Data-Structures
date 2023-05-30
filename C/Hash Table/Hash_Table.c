#include "Hash_Table.h"

#pragma region Constructors
Hash_Table *create_hash(int mode)
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

Hash_Table *create_hash_with_size(int mode, int size)
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
#pragma endregion

#pragma region Destructor
void destroy_hash(Hash_Table hash_table)
{
    free(hash_table._table);
    free(&hash_table);
}
#pragma endregion

#pragma region Private Methods
int num_digits(Hash_Table *hash_table)
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

int div_hash(Hash_Table *hash_table, int key)
{
    int idx = key % hash_table->_table_size;
    if (hash_table->_table[idx] != 0)
    {
        hash_table->_num_collisions++;
        idx = div_hash(hash_table, key + 1);
    }

    return idx;
}

int mid_square_hash(Hash_Table *hash_table, int key)
{
    int idx;
    int r = num_digits(hash_table);

    char square[] = key * key;
    strncpy(square, square + (strlen(square) / 2) - (r / 2), r);
    idx = atoi(square);

    if (hash_table->_table[idx] != 0)
    {
        hash_table->_num_collisions++;
        idx = mid_square_hash(hash_table, key + 1);
    }

    return idx;
}

int digit_folding_hash(Hash_Table *hash_table, int key)
{
    int idx;
    int r = num_digits(hash_table);

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
        idx = digit_folding_hash(hash_table, key + 1);
    }

    return idx;
}

int mult_hash(Hash_Table *hash_table, int key, double a_value)
{
    int random = (key * a_value) + 0.5;
    int idx = hash_table->_table_size * random;

    if (hash_table->_table[idx] != 0)
    {
        hash_table->_num_collisions++;
        idx = mult_hash(hash_table, key + 1, a_value);
    }

    return idx;
}

void resize(Hash_Table *hash_table)
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
#pragma endregion

#pragma region Public Methods
void insert(Hash_Table *hash_table, int key)
{
    if ((double)hash_table->_num_elements / (double)hash_table->_table_size > 0.7)
    {
        resize(hash_table);
    }

    int idx;
    switch (hash_table->_mode)
    {
    case 0:
        idx = div_hash(hash_table, key);
        break;
    case 1:
        idx = mid_square_hash(hash_table, key);
        break;
    case 2:
        idx = digit_folding_hash(hash_table, key);
        break;
    case 3:
        idx = mult_hash(hash_table, key, hash_table->_a_value);
        break;
    default:
        idx = div_hash(hash_table, key);
        break;
    }

    hash_table->_table[idx] = key;
    hash_table->_num_elements++;
}
#pragma endregion