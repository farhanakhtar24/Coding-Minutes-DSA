#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
INPUT :
5 3
c1 1 1
c2 2 1
c3 3 2
c4 0 1
c5 2 3
*/

/*
OUTPUT : c1,c2 ,c4
*/

class Car
{
public:
    string id;
    int x, y;
    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int const dist()
    {
        return (x * x) + (y * y);
    }
};

class CarCompare
{
public:
    bool operator()(Car A, Car B)
    {
        return A.dist() < B.dist(); // will give a max heap
    }
};

void printNearCars(vector<Car> cars, int k)
{
    // create max heap of size K
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);

    // remaining cars
    for (int i = k; i < cars.size(); i++)
    {
        auto car = cars[i];
        auto car2 = max_heap.top();

        if (car.dist() < car2.dist())
        {
            max_heap.pop();
            max_heap.push(car);
        }

        // print all the cars as the result of the question

        while (!max_heap.empty())
        {
            cout << max_heap.top().id << endl;
            max_heap.pop();
        }
    }
}

int main()
{
    int num, k;
    cin >> num >> k;

    string id;
    int x, y;
    vector<Car> cars;

    for (int i = 0; i < num; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }

    printNearCars(cars, k);
    return 0;
}