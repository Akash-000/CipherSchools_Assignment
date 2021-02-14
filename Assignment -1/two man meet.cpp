#include<iostream>
#include<Math.h>
using namespace std;

bool willMeet(int d1, int d2, int v1, int v2)
{
	if(d1>d2 && v1>=v2)
		return false;
	if(d2>d1 && v2>=v1)
		return false;
		
	int rel=abs(v1-v2);
	int dist = abs(d1-d2);
	
	if(dist%rel==0)
		return true;
	return false;
	
}
int main()
{
	int d1, d2;
	int v1, v2;
	
	cout<<"Distances :";
	cin>>d1>>d2;
	cout<<"Velocities";
	cin>>v1>>v2;
	
	if(willMeet(d1,d2,v1,v2)==false)
		cout<<"Not Meet";
	else
		cout<<"Meet";

}
