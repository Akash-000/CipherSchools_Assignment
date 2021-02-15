#include <iostream>

using namespace std;

void mergingarrays(int arr1[], int arr2[], int n, int m)
{
    int arr[n+m];
    
    int i=0, j=0;
    int index=0;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[index] = arr1[i];
            i++;
            index++;
        }
        else if(arr1[i]>arr2[j])
        {
            arr[index] = arr2[j];
            j++;
            index++;
        }
    }
    if(i==n)
    {
        for(j;j<m;j++, index++)
        {
            arr[index]=arr2[j];
        }
    }
    else
    {
        for(i;i<n;i++, index)
            arr[index]=arr[i];
    }
    
    for(int i=0;i<n+m;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr1[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr1[i]);

    int m;
    scanf("%d", &m);
    int arr2[m];
    for(int i=0;i<m;i++)
        scanf("%d", &arr2[i]);
        
    mergingarrays(arr1, arr2, n, m);
    return 0;
}

