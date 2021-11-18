template <class T>
class vector
{
    // Variables
private:
    T *arr;
    int current_size;
    int maximum_size;

    // Methods
public:
    vector()
    {
        current_size = 0;
        maximum_size = 1;
        arr = new T[maximum_size];
    }

    void pushback(T element)
    {
        // 1.
        // Vector array full
        // Create a new array and delete the old one and double the capacity of the vector array
        if (current_size == maximum_size)
        {
            T *oldArray = arr;
            maximum_size = 2 * maximum_size;
            arr = new T[maximum_size];

            for (int i = 0; i < current_size; i++)
            {
                arr[i] = oldArray[i];
            }

            delete[] oldArray;
        }

        // 2.
        // Vector array not full
        arr[current_size] = element;
        current_size++;
    }

    void popback()
    {
        // Without shrinking the array
        if (current_size >= 0)
        {
            current_size--;
        }
    }

    T front()
    {
        return arr[0];
    }

    T back()
    {
        return arr[current_size - 1];
    }

    T at(int i)
    {
        if (i <= maximum_size)
        {
            return arr[i];
        }
    }

    // this means whenever the operator [] is called on an object of this class , function will be fired
    T operator[](int i)
    {
        return arr[i];
    }

    int size()
    {
        return current_size;
    }

    int capacity()
    {
        return maximum_size;
    }
};
