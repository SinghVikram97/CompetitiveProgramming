https://hack.codingblocks.com/practice/p/66/135
#include<bits/stdc++.h>
using namespace std;
/// Minimum steps is number of set bits
/// We apply greedy strategy going for maximum possible jump
int setBits(int n)
{
    int ans=0;
    while(n!=0)
    {
        n=n&(n-1);
        ans++;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<setBits(n)<<endl;
    }
}
