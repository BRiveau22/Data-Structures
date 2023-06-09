#include "Hash_Table.h"

#pragma region Constructors
Hash_Table::Hash_Table(int mode)
{
    this->_mode = mode;
    this->_num_collisions = 0;
    this->_num_elements = 0;
    this->_table_size = 1;
    std::vector<int> *table = new std::vector<int>[this->_table_size];
    this->_table = *table;

    if (mode == 3)
    {
        this->_a_value = (double)rand() / (RAND_MAX + 1);
    }
}

Hash_Table::Hash_Table(int mode, int table_size)
{
    this->_mode = mode;
    this->_num_collisions = 0;
    this->_num_elements = 0;
    this->_table_size = table_size;
    std::vector<int> *table = new std::vector<int>[this->_table_size];
    this->_table = *table;

    if (mode == 3)
    {
        this->_a_value = (double)rand() / (RAND_MAX + 1);
    }
}
#pragma endregion

#pragma region Destructor
Hash_Table::~Hash_Table()
{
}
#pragma endregion

#pragma region Private Methods
int Hash_Table::num_digits()
{
    int temp_size = this->_table_size - 1;
    int r = 0;

    while (temp_size > 0)
    {
        temp_size /= 10;
        r++;
    }
    return r;
}

int Hash_Table::div_hash(int key)
{
    int idx = key % this->_table_size;
    if (this->_table[idx] != 0)
    {
        this->_num_collisions++;
        idx = this->div_hash(key + 1);
    }

    return idx;
}

int Hash_Table::mid_square_hash(int key)
{
    int idx;
    int r = this->num_digits();

    std::string square = std::to_string(key * key);
    std::string sub_str = square.substr((square.size() / 2) - (r / 2), r);
    idx = std::stoi(sub_str);

    if (this->_table[idx] != 0)
    {
        this->_num_collisions++;
        idx = this->mid_square_hash(key + 1);
    }
    return idx;
}

int Hash_Table::digit_folding_hash(int key)
{
    int idx;
    int r = this->num_digits();

    std::string key_str = std::to_string(key);
    while (key_str.size() > 0)
    {
        if (r > key_str.size())
        {
            r = key_str.size();
        }
        idx += std::stoi(key_str.substr(0, r));
        key_str = key_str.substr(r);
    }

    if (this->_table[idx] != 0)
    {
        this->_num_collisions++;
        idx = this->digit_folding_hash(key + 1);
    }

    return idx;
}

int Hash_Table::mult_hash(int key, double a)
{
    int random = (key * a) + 0.5;
    int idx = this->_table_size * random;

    if (this->_table[idx] != 0)
    {
        this->_num_collisions++;
        idx = this->mult_hash(key + 1, a);
    }

    return idx;
}

void Hash_Table::resize_table()
{
    Hash_Table *new_table = new Hash_Table(this->_mode, this->_table_size * 2);
    for (int i = 0; i < this->_table_size; i++)
    {
        if (this->_table[i] != 0)
        {
            new_table->insert(this->_table[i]);
        }
    }

    *this = *new_table;
}
#pragma endregion

#pragma region Public Methods
void Hash_Table::insert(int key)
{
    if ((double)this->_num_elements / (double)this->_table_size > 0.7)
    {
        this->resize_table();
    }

    int idx;
    switch (this->_mode)
    {
    case 0:
        idx = this->div_hash(key);
        break;
    case 1:
        idx = this->mid_square_hash(key);
        break;
    case 2:
        idx = this->digit_folding_hash(key);
        break;
    case 3:
        idx = this->mult_hash(key, this->_a_value);
        break;
    default:
        idx = this->div_hash(key);
        break;
    }

    this->_table[idx] = key;
    this->_num_elements++;
}
#pragma endregion