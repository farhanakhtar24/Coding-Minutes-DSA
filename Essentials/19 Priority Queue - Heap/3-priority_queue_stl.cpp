/*
By default priority_queue makes a max heap
*/
#include <iostream>
#include <queue>
using namespace std;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b; // asceding order
    }
};

int main()
{
    int arr[] = {10, 15, 20, 13, 6, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    // greater<int> is an inbuilt comparator to reverse comparison for putting smaller
    // elements earlier and bigger elements later

    // we can either use greater<int> as a comparator or use custom comparator to compare on our requirement
    // code : priority_queue<int, vector<int>, compare> min_heap;

    for (int x : arr)
    {
        max_heap.push(x);
        min_heap.push(x);
    }

    cout << "Max Heap : ";
    while (!max_heap.empty())
    {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << endl;

    cout << "Min Heap : ";
    while (!min_heap.empty())
    {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }

    return 0;
}