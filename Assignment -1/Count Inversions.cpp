#include <iostream>

using namespace std;

int mergeandcount(int arr[], int l, int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    
    int left[n1], right[n2];
    for(int i=0;i<n1;i++)
    {
        left[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i] = arr[m+1+i];
    }
    
    int res=0, i=0,j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k] =right[j];
            j++;
            res+=n1-i;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    return res;
}

int countInversions(int arr[],int l, int r)
{   
    int count=0;
    if(l<r)
    {
        int mid = l+(r-l)/2;
        count+=countInversions(arr, l, mid);
        count+=countInversions(arr, mid+1, r);
        
        count+=mergeandcount(arr, l, mid, r);
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    cout<<countInversions(arr,0,n-1);

    return 0;
}

