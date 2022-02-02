#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Implement a stack using 2 queues internally as a data structure

class Stack
{
    queue<int> q1, q2;

    // Stack()
    // {
    // }

    bool remote = false; // true for q1 being non empty
public:
    void push(int data)
    {
        if (!q1.empty())
        {
            q1.push(data);
        }
        else
        {
            q2.push(data);
        }
    }

    void pop()
    {
        if (!q1.empty() && remote == true)
        {
            remote = false;
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
        else if (!q2.empty() && remote == false)
        {
            remote = true;
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
    }

    int top()
    {
        if (remote)
        {
            return q1.back();
        }
        else
        {
            return q2.back();
        }
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.pop();
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}