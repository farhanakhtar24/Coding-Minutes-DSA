#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> books;
    books.push("C++");
    books.push("JAVA");
    books.push("JS");
    books.push("Python");

    while (!books.empty())
    {
        cout << books.top() << " ";
        books.pop();
    }
    return 0;
}