#include<iostream>
using namespace std;

bool binary(int arr[],int n, int k)
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int mid = left+(right-left)/2;
		
		if(arr[mid]== k)
			return true;
		else if(arr[mid] > k)
			right= mid-1;
		else
			left= mid+1;
	}
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	int k;
	scanf("%d",&k);
		
	if(binary(arr, n, k)==true)
		cout<<"Present";
	else
		cout<<"Not present";
}
