#include <iostream>
#include <map>
#include <list>

using namespace std;
int main()
{
    map<string, list<string>> phonebook;
    phonebook["prateek"].push_back("4564321");
    phonebook["prateek"].push_back("4578785");
    phonebook["prateek"].push_back("7812454");

    phonebook["Narang"].push_back("5954212");
    phonebook["Narang"].push_back("1231245");
    phonebook["Narang"].push_back("8784652");
    return 0;
}