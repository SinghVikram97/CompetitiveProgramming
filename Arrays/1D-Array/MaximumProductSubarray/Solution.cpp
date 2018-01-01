#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
   ll n;
   cin>>n;
   vector<ll> v(n+1);
   for(int i=1;i<=n;i++)
   {
     cin>>v[i];
   }
   ll dp_max[n+1];
   ll dp_min[n+1];
   dp_max[0]=1;
   dp_min[0]=1;
   for(int i=1;i<=n;i++)
   {
      if(v[i]>=0)
      {
         dp_max[i]=max(v[i],v[i]*dp_max[i-1]);
         dp_min[i]=min(v[i],v[i]*dp_min[i-1]);
      }
      else
      {
         dp_max[i]=max(v[i],v[i]*dp_min[i-1]);
         dp_min[i]=min(v[i],v[i]*dp_max[i-1]);
      }
   }
   ll ans=dp_max[1];
   for(int i=2;i<=n;i++)
   {
       ans=max(dp_max[i],ans);
   }
   cout<<ans;
}
