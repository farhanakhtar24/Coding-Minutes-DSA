#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// PROBLEM : We want to create a rank list based upon the average marks

int marks(vector<int> marks)
{
    int sum = 0;
    for (auto m : marks)
    {
        sum += m;
    }
    return sum;
}

bool sortAlgo(pair<string, vector<int>> s1, pair<string, vector<int>> s2)
{
    int marks1 = marks(s1.second);
    int marks2 = marks(s2.second);

    return marks1 > marks2; // this sorts from highest to lowest
}

int main()
{
    vector<pair<string, vector<int>>> student_marks = {
        {"Rohan", {10, 20, 11}},
        {"Prateek", {10, 21, 3}},
        {"Vivek", {4, 5, 6}},
        {"Rijul", {10, 13, 20}},
    };

    sort(student_marks.begin(), student_marks.end(), sortAlgo);

    return 0;
}