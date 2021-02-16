#include<iostream>
using namespace std;

int missingNumber(int arr[], int n)
{
    int sum_arr=0, actual_sum=0;
    for(int i=0;i<n;i++)
    {
        sum_arr+=arr[i];
    }
    actual_sum = (n+1)*(n+2)/2;
    return actual_sum-sum_arr;
        
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    cout<<missingNumber(arr, n);
}

