#include<iostream>
using namespace std;

int profit=0;
int stockbuysell(int arr[], int n)
{
    if(n==1)
    {
        cout<<"Not sufficient data";
        return 0;
    }
    int i=0;
    while(i<n-1)
    {
        while((i<n-1)&&arr[i]>=arr[i+1])
            i++;
        
        if(i==n-1)
        {
            cout<<"No minima day found";
            break;
        }
        
        int toBuy = i++;
        
        while((i<n)&& arr[i-1]<=arr[i])
        {
            i++;
        }
        int toSell=i-1;
        
        profit+=arr[toSell]-arr[toBuy];
    }
    return profit;
    
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    cout<<stockbuysell(arr, n);
    return 0;
}

