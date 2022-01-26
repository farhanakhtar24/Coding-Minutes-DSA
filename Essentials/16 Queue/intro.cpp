/*
Stack : LIFO => Last In First Out
Queue : FIFO => First In First Out

Queue adds at the end and pop at the front

Using array we can only implement a circular queue of fixed size

Methods:
Pop : O(1)
Push : O(1)
Front : O(1)
*/

#include <iostream>
#include "queue.h";
using namespace std;

int main()
{
    Queue nums(7);

    nums.push(1);
    nums.push(2);
    nums.push(3);
    nums.push(4);
    nums.push(5);
    nums.push(6);
    nums.push(7);
    nums.push(8);
    nums.pop();
    nums.pop();
    nums.push(9);

    while (!nums.empty())
    {
        cout << nums.getfront() << " ";
        nums.pop();
    }

    return 0;
}
