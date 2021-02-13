#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
		
	sort(arr, arr+n);
	
	int left=0, right=n-1;
	while(left<=right)
	{
		if(left==right)
			cout<<arr[left];
		else
			cout<<arr[right]<<" "<<arr[left]<<" ";
		
		left++;right--;
	}
	
	
}
