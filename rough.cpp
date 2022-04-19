#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Student
{
    vector<double> marksArray;

public:
    string id;
    double totalMarks;
    double percentage;
    Student()
    {
        this->totalMarks = 0;
        this->percentage = 0;
    };
    void addMarks(double marks)
    {
        marksArray.push_back(marks);
        totalMarks += marks;
        percentage = totalMarks / marksArray.size();
    }
    void marksInEachSubject()
    {
        int itr = 1;
        for (auto x : marksArray)
        {
            cout << "Subject " << itr << " : " << x << endl;
        }
    }
    void printStudentMarksAndPercentage()
    {
        cout << "Total Marks : " << totalMarks << endl;
        cout << "Percentage : " << percentage << endl;
    }
};

int main()
{
    // for 2 students
    vector<Student> school(2);

    for (int i = 0; i < school.size(); i++)
    {
        cout << "Student " << i + 1 << endl;
        for (int j = 0; j < 10; j++)
        {
            double mark;
            cout << "S" << j + 1 << " marks : ";
            cin >> mark;
            school[i].addMarks(mark);
        };
        school[i].printStudentMarksAndPercentage();
    }

    double maxPercentage = 0;
    for (auto x : school)
    {
        maxPercentage = max(x.percentage, maxPercentage);
    }
    cout << "Max Percentage" << maxPercentage << endl;
    return 0;
}