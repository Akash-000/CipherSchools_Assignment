/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a=*b;
    *b=temp;
}

void anagram(string a, int left, int right)
{
    if(left==right)
    {
        cout<<a<<endl;
    }
    else{
        for(int i=left;i<=right;i++)
        {
            swap(a[left], a[i]);
            anagram(a, left+1, right);
            swap(a[left], a[i]);
        }
    }
}

int main()
{
    string s;
    cin>>s;
    
    int n = s.size();
    
    anagram(s, 0, n-1);

    return 0;
}

