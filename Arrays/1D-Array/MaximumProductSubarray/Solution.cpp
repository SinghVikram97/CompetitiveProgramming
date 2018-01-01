/// 4
/// 2 3 -3 -4         /// Construct dp_max array for this.
/// 3
/// 2 -3 4
It is not similar to find the max sum in an array. 
In max sum we can discard the previous sum as soon as it is zero.
In multipication , we can not do it as product of two negative numbers become positive numbers
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
   for(int i=0;i<=n;i++)
   {
       cout<<dp_max[i]<<" ";
   }
}
