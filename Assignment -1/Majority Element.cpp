#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	unordered_map<int, int> m;
	
	for(int i=0;i<n;i++)
		m[arr[i]]++;
	
	int flag=0;
		
	for(auto x: m)
	{
	    if(x.second > n/2)
	    {
	        printf("The Majority Element is : %d with %d counts",x.first,x.second);
	        flag=1;
	        break;
	    }
	}
	if(flag==0)
	    printf("Not Present");
	
}
