#include<iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	int first=0, last=n-1;
	while(first<last)
	{
		if(arr[first]==1 && arr[last]==0)
		{
			int temp=arr[first];
			arr[first] = arr[last];
			arr[last] = temp;
		}
		else if(arr[first]==0)
			first++;
		else if(arr[last]==1)
			last--;
	}
	for(int i=0;i<n;i++)
		printf("%d ", arr[i] );
}
