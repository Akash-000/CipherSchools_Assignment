#include<iostream>
#include<vector>

using namespace  std;

void subset_sum(int arr[], int len, int beg, int k,int sum, vector<int> v)
{
    if(sum==k)
    {
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        
        cout<<endl;       
        return;
    }
    for(int i=beg;i<len;i++)
    {
        v.push_back(arr[i]);
        subset_sum(arr, len, i+1, k, sum+arr[i], v);
        v.pop_back();
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
        
    int k;
    cout<<"Enter sum to be searched : ";
    scanf("%d",&k);
    vector<int> v;
    
    int calculated_sum=0;
    
    subset_sum(arr,n, 0, k,calculated_sum, v);
}
