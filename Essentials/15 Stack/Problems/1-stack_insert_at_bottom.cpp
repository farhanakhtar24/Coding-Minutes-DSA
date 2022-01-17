#include <iostream>
#include <stack>

using namespace std;

// Insert element at the bottom of the stack (below the first element which was pushed)
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

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    insertAtBottom(s, 18);
    insertAtBottom(s, 15);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}