public class Dynamic_Array
{
    private int m_length;
    private int m_capacity;
    private double m_scale_factor;
    private int[] m_array;

    // Constructors
    Dynamic_Array()
    {
        this.m_length = 0;
        this.m_capacity = 1;
        this.m_scale_factor = 2;
        this.m_array = null;
    }

    Dynamic_Array(double scaling_factor, int initial_capacity)
    {
        this.m_length = 0;
        this.m_capacity = initial_capacity;
        this.m_scale_factor = scaling_factor;
        this.m_array = null;
    }

    Dynamic_Array(double scaling_factor, int length, int default_value)
    {
        this.m_length = length;
        this.m_capacity = length;
        this.m_scale_factor = 2;
        this.m_array = new int[length];
        for (int i = 0; i < length; i++)
        {
            this.m_array[i] = default_value;
        }
    }

    // Getters / Setters
    int get_length()
    {
        return this.m_length;
    }

    int get_capacity()
    {
        return this.m_capacity;
    }

    double get_scale_factor()
    {
        return this.m_scale_factor;
    }

    void set_scale_factor(double scale_factor)
    {
        this.m_scale_factor = scale_factor;
    }

    // Methods
    void append(int data)
    {
        // Check for array overflow
        if (this.m_length == this.m_capacity)
        {
            // Create new array
            int[] new_array = new int[(int)(this.m_capacity * this.m_scale_factor)];
            // Copy old array to new array
            for (int i = 0; i < this.m_length; i++)
            {
                new_array[i] = this.m_array[i];
            }
            // Set new array as current array
            this.m_array = new_array;
            // Update capacity
            this.m_capacity = (int)(this.m_capacity * this.m_scale_factor);
        }

        // Append data to array
        this.m_array[this.m_length] = data;
        this.m_length++;
    }

    void prepend(int data)
    {
        // Check for array overflow
        if (this.m_length == this.m_capacity)
        {
            // Create new array
            int[] new_array = new int[(int)(this.m_capacity * this.m_scale_factor)];
            // Copy old array to new array
            for (int i = 1; i < this.m_length + 1; i++)
            {
                new_array[i] = this.m_array[i - 1];
            }
            // Set new array as current array
            this.m_array = new_array;
            // Update capacity
            this.m_capacity = (int)(this.m_capacity * this.m_scale_factor);
        }

        // prepend data to array
        this.m_array[0] = data;
        this.m_length++;
    }

    void remove_last()
    {
        int[] new_array = new int[this.m_capacity];
        this.m_array = new_array;
        for (int i = 0; i < m_length - 1; i++)
        {
            this.m_array[i] = this.m_array[i];
        }
    }

    void remove_first()
    {
        int[] new_array = new int[this.m_capacity];
        this.m_array = new_array;
        for (int i = 1; i < m_length + 1; i++)
        {
            this.m_array[i - 1] = this.m_array[i];
        }
    }

    void clear()
    {
        while (this->m_length > 0)
        {
            this->remove_last();
        }
    }

    int find_first_of(int data)
    {
        for (int i = 0; i < this.m_length; i++)
        {
            if (this.m_array[i] == data)
            {
                return i;
            }
        }
        return -1;
    }

    int find_last_of(int data)
    {
        for (int i = this.m_length - 1; i >= 0; i--)
        {
            if (this.m_array[i] == data)
            {
                return i;
            }
        }
        return -1;
    }

    bool contains(int data)
    {
        for (int i = 0; i < this.m_length; i++)
        {
            if (this.m_array[i] == data)
            {
                return true;
            }
        }
        return false;
    }
}