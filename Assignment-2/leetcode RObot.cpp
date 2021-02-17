/*class Solution {
public:
    
    int allpaths=0;

void allpossiblePaths(vector<vector<int>>v, int i, int j, stack<int> s)
    {
        int m=v.size();
        int n = v[0].size();

        if(i==m-1 && j== n-1)
        {
            s.push(v[i][j]);
            allpaths=allpaths+1;
            s.pop();
        }

        s.push(v[i][j]);
        if(j+1>=0 && j+1<n)
        {
            allpossiblePaths(v, i, j+1, s);
        }
        if(i+1>=0 && i+1<m)
        {
            allpossiblePaths(v,i+1, j, s);
        }

        s.pop();

    }


int uniquePaths(int m, int n) {
        
        vector<vector<int>> v;
    for(int i=0;i<m;i++)
    {
        vector<int> row_data;
        for(int j=0;j<n;j++)
        {
            row_data.push_back(1);
        }
        v.push_back(row_data);
    }
    
    stack<int> s;
    
    allpossiblePaths(v,0,0,s);
    
    return allpaths;
        
    }
};*/




//ABOVE CODE WAS SUBMITTED TO LEETCODE BUT GETTING TLE




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//Below code is FULL-PROGRAM




#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int allpaths=0;

void allpossiblePaths(vector<vector<int> >v, int i, int j, stack<int> s)
{
    int m=v.size();
    int n = v[0].size();
    
    if(i==m-1 && j== n-1)
    {
        s.push(v[i][j]);
        allpaths=allpaths+1;
        s.pop();
    }
    
    s.push(v[i][j]);
    if(j+1>=0 && j+1<n)
    {
        allpossiblePaths(v, i, j+1, s);
    }
    if(i+1>=0 && i+1<m)
    {
        allpossiblePaths(v,i+1, j, s);
    }
    
    s.pop();
    
}

int main()
{
    int m,n;
    cin>>m>>n;
    
    vector<vector<int> > v;
    for(int i=0;i<m;i++)
    {
        vector<int> row_data;
        for(int j=0;j<n;j++)
        {
            row_data.push_back(1);
        }
        v.push_back(row_data);
    }
    
    stack<int> s;
    
    allpossiblePaths(v,0,0,s);
    
    cout<<allpaths;
}
