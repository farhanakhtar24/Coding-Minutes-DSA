#include <iostream>
using namespace std;
class student
{
    char name[25];
    int m, p, d;
    float avrg;

public:
    void get_data();
    void display();
};
void student::get_data()
{
    cout << "Enter your name \n";
    cin.getline(name, 25);
    cout << "Enter marks in your subject" << endl;
    cout << "1. Electrical Machine \n";
    cin >> m;
    cout << "2. Power System \n";
    cin >> p;
    cout << "3. Digital \n";
    cin >> d;
}
void student::display()
{
    cout << "Entered name is " << name << endl;
    avrg = (m + p + d) / 3;
    cout << "Average of marks in M,P and d is " << avrg;
}
int main()
{

    student s1;
    s1.get_data();
    s1.display();

    return 0;
}
