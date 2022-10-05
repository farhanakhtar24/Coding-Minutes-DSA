#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// SUMMARY
// 0.Iterate over all the elements of str .
// 1.We have to push all the elements inside the stack until we hit char=')'
// 2.When we hit char=')' we have to check if there is an operator present or not . If there is an operator present inside stack
// then we pop all the elements till we hit char='(' or if the stack empties. and we pop it too outside the while loop.
// 3.Then we check if the operator found variable is false or not.
// 4.If it's false then we it means we hit a case where there were redundant paranthesis.
// 5.Return false outside of for loop to complete the function

bool redundant_paranthesis(string str)
{
    stack<char> s;
    for (auto ch : str)
    {
        if (ch != ')')
        {
            s.push(ch); // pushing all the elements such as a,b,+,\ etc
        }
        else if (ch == ')')
        {
            bool operator_found = false;
            while (!s.empty() && s.top() != '(')
            {
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    operator_found = true;
                }
                s.pop();
            }
            s.pop(); // for removing the last opening bracket which is left in the stack
            if (operator_found == false)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string str = "((a+b)+c)()";
    if (redundant_paranthesis(str))
    {
        cout << "YES contains redundant paranthesis !!" << endl;
    }
    else
    {
        cout << "NO doesn't contain redundant paranthesis !!" << endl;
    }
    return 0;
}