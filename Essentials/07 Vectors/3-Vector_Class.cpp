#include <iostream>

// Making the class as a header file and then using it from outside the code
#include "vector.h"
using namespace std;

// class vector
// {
//     // Variables
// private:
//     int *arr;
//     int current_size;
//     int maximum_size;

//     // Methods
// public:
//     vector()
//     {
//         current_size = 0;
//         maximum_size = 1;
//         arr = new int[maximum_size];
//     }

//     void pushback(int element)
//     {
//         // Vector array full
//         // Create a new array and delete the old one and double the capacity of the vector array
//         if (current_size == maximum_size)
//         {
//             int *oldArray = arr;
//             maximum_size = 2 * maximum_size;
//             arr = new int[maximum_size];

//             for (int i = 0; i < current_size; i++)
//             {
//                 arr[i] = oldArray[i];
//             }

//             delete[] oldArray;
//         }

//         // Vector array not full
//         arr[current_size] = element;
//         current_size++;
//     }

//     void popback()
//     {
//         // Without shrinking the array
//         if (current_size >= 0)
//         {
//             current_size--;
//         }
//     }

//     int front()
//     {
//         return arr[0];
//     }

//     int back()
//     {
//         return arr[current_size - 1];
//     }

//     int at(int i)
//     {
//         if (i <= maximum_size)
//         {
//             return arr[i];
//         }
//     }

//     // this means whenever the operator [] is called on an object of this class , function will be fired
//     int operator[](int i)
//     {
//         return arr[i];
//     }

//     int size()
//     {
//         return current_size;
//     }

//     int capacity()
//     {
//         return maximum_size;
//     }
// };

int main()
{
    vector<char> vc;
    vc.pushback('a');

    cout << vc[0] << endl;

    vector<int> v;
    v.pushback(1);
    v.pushback(2);
    v.pushback(3);
    v.pushback(4);
    v.pushback(5);
    v.pushback(18);
    v.popback();

    cout << v.size() << " " << v.capacity() << endl;
    cout << v.front() << " " << v.back() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}