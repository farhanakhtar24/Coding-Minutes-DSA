#include<iostream> 
using namespace std; 

int main(){ 
    float amount; 
    int units; 
    char s[30]; 
    cout<<"Enter name of user"<<endl; 
    cin.get(s,30); 
    cout<<"Enter number of units"<<endl; 
    cin>>units; 
    if(units<= 100){ 
        amount=0.6*units; 
    } 
    else if(units>100 && units<= 300) 
    { 
        amount=0.8*units; 
    } 
    else { 
        amount=0.9*units; 
    } 
    cout<<"Name of user is "<< s<<endl; 
    cout<<"Number of units "<<units<<endl; 
    if(amount<=50){ 
        amount=50; 
        cout<<" minimum amount is Rs."<<amount; 
    } else if(amount>300){ 
        amount=1.15*amount; 
        cout<<"Total bill amount is Rs." <<amount; 
    }else{ 
        cout<<"your bill amount Rs."<<amount<<endl;} 
    return 0; 
}
