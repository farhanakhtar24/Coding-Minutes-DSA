#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int data)
{
    // base case
    if (s.empty())
    {
        s.push(data);
        return;
    }

    // rec case
    int temp = s.top();
    s.pop();

    insertAtBottom(s, data);
    s.push(temp);
}

// Reverse stack using recursion
void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}