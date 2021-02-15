#include <iostream>
#include<queue>
using namespace std;

int maxelement(int arr[], int k)
{
    int maximum=-500;
    int indexmax=0;
    for(int i=0;i<k;i++)
    {
        if(arr[i]>maximum)
        {
            maximum=arr[i];
            indexmax=i;
        }
    }
    return indexmax;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    int k;
    printf("Enter value of K : ");
    scanf("%d",&k);
    int etc[k];
    for(int i=0;i<k;i++)
        etc[i] = arr[i];

    
    int indexmax = maxelement(etc, k);
    
    //cout<<etc[indexmax];
    
    
    for(int i=k;i<n;i++)
    {
        if(arr[i]<etc[indexmax])
        {
            etc[indexmax]=arr[i];
            indexmax=maxelement(etc, k);
        }
    }
    for(int i=0;i<k;i++)
        cout<<etc[i]<<" ";
    
    return 0;
}

