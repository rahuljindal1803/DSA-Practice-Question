class Polynomial
{
public:
    int *degcoeff;
    int capacity;

public:
    Polynomial()
    {
        degcoeff = new int[10];
        for (int i = 0; i < 10; i++)
        {
            degcoeff[i] = 0;
        }
        capacity = 10;
    }
    Polynomial(Polynomial const &d)
    {
        this->degcoeff = new int[d.capacity];
        for (int i = 0; i < d.capacity; i++)
        {
            this->degcoeff[i] = d.degcoeff[i];
        }
        this->capacity = d.capacity;
    }

    void setcoefficient(int deg, int coeff)
    {
        if (deg >= capacity)
        {
            int size = deg + 1;
            int *newarray = new int[size];
            for (int i = 0; i < capacity; i++)
            {
                newarray[i] = this->degcoeff[i];
            }
            for (int i = capacity; i < size; i++)
            {
                newarray[i] = 0;
            }
            delete[] this->degcoeff;
            this->degcoeff = newarray;
            this->capacity = size;
        }
        this->degcoeff[deg] = coeff;
    }
    Polynomial operator+(Polynomial &p)
    {
        Polynomial newp;
        newp.capacity = max(p.capacity, capacity);
        newp.degcoeff = new int[newp.capacity];
        if (capacity < p.capacity)
        {
            int k;
            for (k = 0; k < capacity; k++)
            {
                newp.degcoeff[k] = degcoeff[k] + p.degcoeff[k];
            }
            for (; k < p.capacity; k++)
            {
                newp.degcoeff[k] = p.degcoeff[k];
            }
        }
        else
        {
            int k;
            for (k = 0; k < p.capacity; k++)
            {
                newp.degcoeff[k] = degcoeff[k] + p.degcoeff[k];
            }
            for (; k < capacity; k++)
            {
                newp.degcoeff[k] = degcoeff[k];
            }
        }
        return newp;
    }
    Polynomial operator-(Polynomial &p)
    {
        Polynomial newp;
        newp.capacity = max(p.capacity, capacity);
        newp.degcoeff = new int[newp.capacity];
        if (capacity < p.capacity)
        {
            int k;
            for (k = 0; k < capacity; k++)
            {
                newp.degcoeff[k] = degcoeff[k] - p.degcoeff[k];
            }
            for (; k < p.capacity; k++)
            {
                newp.degcoeff[k] = -p.degcoeff[k];
            }
        }
        else
        {
            int k;
            for (k = 0; k < p.capacity; k++)
            {
                newp.degcoeff[k] = degcoeff[k] - p.degcoeff[k];
            }
            for (; k < capacity; k++)
            {
                newp.degcoeff[k] = degcoeff[k];
            }
        }
        return newp;
    }
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial newp;
        newp.capacity = p.capacity + capacity;
        newp.degcoeff = new int[newp.capacity];
        for (int i = 0; i < newp.capacity; i++)
        {
            newp.degcoeff[i] = 0;
        }
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < p.capacity; j++)
            {
                newp.degcoeff[i + j] += degcoeff[i] * p.degcoeff[j];
            }
        }
        return newp;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degcoeff[i])
            {
                cout << degcoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};