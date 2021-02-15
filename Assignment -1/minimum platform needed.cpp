#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int minplatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);
    
    int platform=1, total=1;
    int i=1, j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            platform++;
            i++;
        }
        else if(arr[i]>dep[j])
        {
            platform--;
            j++;
        }
        if(platform>total)
        {
            total=platform;
        }
    }
    return total;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    int dep[n];
    
    for(int i=0;i<n;i++)
        scanf("%d", &dep[i]);
    
    cout<<minplatform(arr, dep, n);
    return 0;
}

