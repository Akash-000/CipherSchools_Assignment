#include<iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
		
	int left=0, mid=0, right=n-1;
	
	while(mid<=right)
	{
		if(arr[mid]==1)
			mid++;
		else if(arr[mid]==0)
		{
			int temp=arr[mid];
			arr[mid]=arr[left];
			arr[left]=temp;
			mid++;
			left++;
		}
		else
		{
			int temp=arr[mid];
			arr[mid]=arr[right];
			arr[right]=temp;	
			right--;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d", arr[i]);
}
