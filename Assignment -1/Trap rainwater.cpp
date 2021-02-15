#include <iostream>

using namespace std;
int min(int a, int b)
{
    return a>b?b:a;
}

int traprainwater(int arr[], int n)
{
    int left[n];
    left[0]=arr[0];
    int right[n];
    right[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>left[i-1])
            left[i]=arr[i];
        else
            left[i]=left[i-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>right[i+1])
            right[i]=arr[i];
        else
            right[i]=right[i+1];
    }
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=min(left[i],right[i])-arr[i];
    }
    return sum;
    
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);


    printf("%d",traprainwater(arr, n));
    return 0;
}

