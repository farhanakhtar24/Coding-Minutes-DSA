// MAX HEAP
#include <vector>
using namespace std;

class Heap
{
    vector<int> v;

    void heapify(int i)
    {
        int left = 2 * i;
        int right = (2 * i) + 1;
        int minIndex = i;
        if (left < v.size() && v[left] < v[i])
        {
            minIndex = left;
        }
        if (right < v.size() && v[right] < v[minIndex])
        {
            minIndex = right;
        }

        if (minIndex != i)
        {
            swap(v[i], v[minIndex]);
            heapify(minIndex);
        }
    }

public:
    Heap(int default_size = 10)
    {
        v.reserve(default_size + 1);
        v.push_back(-1);
    }

    void push(int data) // T.C : O(LogN)
    {
        // add data to end of the heap
        v.push_back(data);
        int index = v.size() - 1;
        int parent = index / 2;

        while (index > 1 && v[index] < v[parent])
        {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop() // T.C : O(LogN)
    {
        // Swap first and last element
        int index = v.size() - 1;
        swap(v[1], v[index]);
        v.pop_back();
        heapify(1);
    }

    bool empty()
    {
        return v.size() == 1;
    }
};