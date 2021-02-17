#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printStack(stack<int> s)
{
    
    
    
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}

void possiblePaths(vector<vector<int> > v, int i, int j, stack<int> s)
{
    int m=v.size();
    int n=v[0].size();
    if(i==m-1 && j==n-1)
    {
        s.push(v[i][j]);
        printStack(s);
        cout<<endl;
        s.pop();
    }
    
    s.push(v[i][j]);
    
    if(j+1>=0 && j+1<n)
    {
        possiblePaths(v, i, j+1, s);
    }
    
    if(i+1>=0 && i+1<m)
    {
        possiblePaths(v, i+1, j, s);
    }
    s.pop();
}

int main()
{
    vector<vector<int> > v;//={{1,2,3},{4,5,6},{7,8,9}};
    int row, column;
    
    scanf("%d", &row);
    scanf("%d", &column);
    
    for(int i=0;i<row;i++)
    {
        vector<int> row_data;
        for(int j=0;j<column;j++)
        {
            int input;
            cin>>input;
            row_data.push_back(input);
        }
        v.push_back(row_data);
    }
    
    
    
    
    stack<int> s;
            
    possiblePaths(v,0,0,s);
    
}
