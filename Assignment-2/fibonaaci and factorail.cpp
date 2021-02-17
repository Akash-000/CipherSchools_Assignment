#include <iostream>

using namespace std;

int fibonaaci(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    
    return fibonaaci(n-1)+fibonaaci(n-2);
}

int factorial(int n)
{
    if(n==1 || n==0)
        return 1;
    
    return n*factorial(n-1);
}

int main()
{
    int choice;
    cout<<"press 1 to choose factorial and 2 to choose fibonaaci numbers :";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"factorial is choosen :-/n";
            cout<<"Enter N : ";
            int n;
            cin>>n;
            cout<<factorial(n);
            break;
            
        }
        case 2:
        {
            cout<<"fibonaaci is choosen : -/n";
            cout<<"Enter N : ";
            int n;
            cin>>n;
            cout<<fibonaaci(n);
            break;
        }
        default:
        {
            cout<<"Invalid selection";
        }
    }
}

