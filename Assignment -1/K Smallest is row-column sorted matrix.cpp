#include<iostream>
using namespace std;

#define SIZE 105

int getcount(int arr[SIZE][SIZE], int mid, int row, int column)
{
    int count=0;
    int c=0;
    int r=row-1;
    while(r>=0 && c<column)
    {
        if(arr[r][c]<=mid)
        {
            c++;
            count+=r+1;
        }
        else
        {
            r--;
        }
    }
    return count;
}

int printSmallestKElement(int row, int column, int arr[SIZE][SIZE], int k)
{
    int low = arr[0][0];
    int high = arr[row-1][column-1];
    
    while(low<high)
    {
        int mid = low+(high-low)/2;
        
        int count = getcount(arr, mid, row, column);
        
        if(count>=k)
            high=mid;
        else
            low=mid+1;
    }
    return low;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    
    int arr[SIZE][SIZE];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    
    int k;
    cout<<"Enter value of K :";
    scanf("%d",&k);
    
    cout<<printSmallestKElement(m,n,arr,k);
    
}
