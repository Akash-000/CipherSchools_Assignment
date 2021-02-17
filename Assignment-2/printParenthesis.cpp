#include <iostream>

using namespace std;

void printParenthesis(int left, int right, string s)
{
    if(left>right)
        return;
    if(left==0 && right==0)
    {
        cout<<s<<endl;
        return;
    }
    
    if(left>0)
    {
        printParenthesis(left-1, right,s+"(");
    }
    if(right>0)
    {
        printParenthesis(left, right-1,s+")");
    }
    
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int left=n;
    int right = n;
    string s="";
    printParenthesis(left, right, s);
}

