#include <iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

string mapper(char c)
{
    if(c=='2')
        return "abc";
    if(c=='3')
        return "def";
    if(c=='4')
        return "ghi";
    if(c=='5')
        return "jkl";
    if(c=='6')
        return "mno";
    if(c=='7')
        return "pqrs";
    if(c=='8')
        return "tuv";
    if(c=='9')
        return "wxyz";
    
}

vector<string> printpattern(string s)
{
    if(s.length()==0)
    {
        vector<string> empty;
        empty.push_back("");
        return empty;
    }
    
    char c = s[0];
    
    vector<string> total;
    string firstans = mapper(c);
    
    vector<string> smallerans = printpattern(s.substr(1));
    
    for(int i=0;i<firstans.length();i++)
    {
        
        for(int j=0;j<smallerans.size();j++)
        {
            string ans = firstans[i]+smallerans[j];
            total.push_back(ans);
        }
    }
    return total;
}

int main()
{
    int n;
    scanf("%d",&n);
        
    stringstream x;
    x<<n;
    string s = x.str();
    
    vector<string> v;
    
    v = printpattern(s);
    
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
        
    
    return 0;
}

