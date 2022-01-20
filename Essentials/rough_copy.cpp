#include <iostream>

using namespace std;
class price_last_year
{
public:
    int price;
    virtual void setdata(int a = 50)
    {
        price = a;
    }
    virtual void show(void)
    {
        cout << "Updated price is : " << price << endl;
    }
};

class price_this_year : public price_last_year
{
public:
    void setdata(int a = 60)
    {
        price = a;
    }

    void show(void)
    {
        cout << "Updated price is : " << price << endl;
    }
};

int main(void)
{
    price_last_year *this_year_ptr = new price_this_year;
    // price_last_year obj_last;
    // price_this_year obj_this;

    // this_year_ptr = &obj_this; // a pointer of base class pointing to next year object, but virtual function not working

    this_year_ptr->setdata();
    this_year_ptr->show();

    return 0;
}