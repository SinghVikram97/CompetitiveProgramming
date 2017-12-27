#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[5005];
ll minimum_jumps(vector<ll> v,ll index)
{
    ll n=v.size();
    if(index==n)
    {
       return 0;
    }
    else if(index>n)
    {
       return INT_MAX;
    }
    if(dp[index]==-1)
    {
       /// We start from 0 and we have to reach n
    /// At each step we can take jump of 1 to v[i]
    ll ans=INT_MAX;
    for(ll i=1;i<=v[index];i++)
    {
      ans=min(ans,1+minimum_jumps(v,index+i));
    }
    dp[index]=ans;
    }
   return dp[index];
}
int main()
{
   ll n;
   cin>>n;
   vector<ll> v(n);
   for(int i=0;i<n;i++)
   {
     cin>>v[i];
   }
   for(int i=0;i<=n;i++)
   {
     dp[i]=-1;
   }
   cout<<minimum_jumps(v,0);
}
