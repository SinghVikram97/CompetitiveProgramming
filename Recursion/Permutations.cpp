#include<bits/stdc++.h>
using namespace std;
void permutations(string s,int index)  /// Strings passed by value
{
    if(index==s.length())
    {
        cout<<s<<endl;
        return;
    }
    /// Swap every character with the 1st character and permute for remaining n-1 characters
    for(int i=index;i<s.length();i++)
    {
        swap(s[index],s[i]);
        permutations(s,index+1);
        swap(s[index],s[i]); /// Backtracking
        /// As passed by value remove this statement then also output correct? Yes
        /// But if you use arrays you need to include this as arrays passed by reference
    }
}
int main()
{
    string s;
    cin>>s;
    permutations(s,0);
}
