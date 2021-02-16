#include<iostream>
using namespace std;

int binarysearch(int arr[], int l, int h, int key)
{
	if(l>h)
		return -1;
		
	int mid= l+(h-l)/2;
	
	if(arr[mid]==key)
		return mid;
		
	if(arr[l]<=arr[mid])
	{
		if(key>=arr[l] && key <=arr[mid])
			return binarysearch(arr, l, mid-1, key);
			
		return binarysearch(arr, mid+1, h, key);
	}
	
	if(key>=arr[mid]&&key<=arr[h])
		return binarysearch(arr, mid+1, h, key);
	return binarysearch(arr, l, mid-1, key);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
		
		
	int key=0;
	scanf("%d", &key);
	int index = binarysearch(arr, 0, n-1, key);
	
	if(index==-1)
		cout<<"Not found";
	else
		cout<<"Found at index : "<<index;
}
