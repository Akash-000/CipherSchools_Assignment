#include <iostream>

using namespace std;

int maximum(int a, int b)
{
    return a>b?a:b;
}

int kadanealgo(int arr[], int n)
{
    int max_curr=arr[0];
    int max_all=arr[0];
    for(int i=1;i<n;i++)
    {
        max_curr=maximum(arr[i], max_curr+arr[i]);
        if(max_curr>max_all)
            max_all=max_curr;
    }
    return max_all;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    cout<<kadanealgo(arr, n);
    
    return 0;
}

