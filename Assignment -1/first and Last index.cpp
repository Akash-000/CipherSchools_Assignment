#include<iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
		
		
	int k;
	scanf("%d", &k);
	
	int indexfirst=0;
	int left=0, right=n-1;
	while(left<=right)
	{
		int mid = left+(right-left)/2;
		
		if(arr[mid]==k && arr[mid-1]<k)
		{
			indexfirst=mid;
			break;
		}
			
		else if(arr[mid]<k)
			left=mid+1;
		else
			right=mid-1;
	}
	cout<<indexfirst<<" ";
	
	left=0;right=n-1;
	int indexlast=-1;
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		if(arr[mid]==k && arr[mid+1]>k)
		{
			indexlast=mid;
			break;
		}
		else if(arr[mid] > k)
			right=mid-1;
		else
			left=mid+1;
	}
	cout<<indexlast;
}
