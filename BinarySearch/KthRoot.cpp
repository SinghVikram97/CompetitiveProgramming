/// Greatest integer whose square less than equal to n(floor)
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll power(ll x,ll y)
{
    if(y==0)
    {
        return 1;
    }
    else if(y==1)
    {
        return x;
    }
    ll smallPower=power(x,y/2);
    smallPower=smallPower*smallPower;
    if(y%2==0)
    {
        return smallPower;
    }
    else
    {
        return smallPower*x;
    }
}
ll kthRoot(ll n,ll k)
{
   ll start=1,end=n,ans;
   while(start<=end)
   {
       ll mid=(start)+(end-start)/2;
       if(pow(mid,k)<=n)
       {
           /// See if we can increase mid because we want the greatest
           ans=mid;
           start=mid+1;
       }
       else
       {
           end=mid-1;
       }
   }
   return ans;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       ll n,k;
       cin>>n>>k;
       cout<<kthRoot(n,k)<<endl;
   }
}
