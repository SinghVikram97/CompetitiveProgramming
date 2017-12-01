Can do buy bitmasking subsets of a set
#include<bits/stdc++.h>
using namespace std;
int length(string s)
{
    return pow(2,s.length());
}
void subsequence(string s,string out,int i)
{
    if(i==s.length())
    {
        cout<<out<<" ";
        return;
    }
    /// Don't include
    subsequence(s,out,i+1);
    /// Include current character
    out.push_back(s[i]);       /// Can't do out[j]=s[i]
    subsequence(s,out,i+1);
}
int main()
{
    string s,out;
    cin>>s;
    cout<<length(s)<<endl;
    subsequence(s,out,0);
}
