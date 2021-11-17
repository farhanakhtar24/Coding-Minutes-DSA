#include <iostream>
using namespace std;

class vector
{
    // Variables
private:
    int *arr;
    int currentSize;
    int maximumSize;

public:
    //Methods
    vector()
    {
        currentSize = 0;
        maximumSize = 1;
        arr = new int[maximumSize];
    }

    void pushback(int element)
    {
        // if array is full
        if (currentSize = maximumSize)
        {
            int *oldArray = arr;
            maximumSize = 2 * maximumSize;
            arr = new int[maximumSize];

            for (int i = 0; i < currentSize; i++)
            {
                arr[i] = oldArray[i];
            }
            delete[] oldArray;
        }
        //if array is still empty
        arr[currentSize] = element;
        currentSize++;
    }

    void popback()
    {
        if (currentSize > 0)
        {
            currentSize--;
        }
    }

    int front()
    {
        return arr[0];
    }

    int back()
    {
        return arr[currentSize - 1];
    }

    int at(int i)
    {
        if (i <= maximumSize)
        {
            return arr[i];
        }
    }

    int size()
    {
        return currentSize;
    }

    int capacity()
    {
        return maximumSize;
    }
};

int main()
{
    vector v;
    v.pushback(1);
    v.pushback(2);
    v.pushback(3);
    v.pushback(4);
    v.pushback(5);

    cout << v.size() << " " << v.capacity() << endl;
    return 0;
}