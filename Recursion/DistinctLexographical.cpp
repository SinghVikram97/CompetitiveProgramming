#include<bits/stdc++.h>
using namespace std;
set<string> a;  /// Set doesn't allow duplicates.
void permutations(string s,int index)
{
    if(index==s.length())
    {
        a.insert(s);
        return;
    }
    /// Swap every character with the 1st character and permute for remaining n-1 characters
    for(int i=index;i<s.length();i++)
    {
        swap(s[index],s[i]);
        permutations(s,index+1);
        swap(s[index],s[i]);
    }
}
int main()
{
    string s;
    cin>>s;
    permutations(s,0);
    for(auto it:a)
    {
        cout<<it<<endl;
    }
}
