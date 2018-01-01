/// 4
/// 2 3 -3 -4
/// 3
/// 2 -3 -4
/// It is not similar to find the max sum in an array.
/// In max sum we can discard the previous sum as soon as it is zero.
/// In multipication , we can not do it as product of two negative numbers become positive numbers
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
   ll n;
   cin>>n;
   vector<ll> v(n);
   for(int i=0;i<n;i++)
   {
     cin>>v[i];
   }
   ll minimum_so_far=1;
   ll maximum_so_far=1;
   ll global_maximum=INT_MIN;
   for(int i=0;i<n;i++)
   {
     if(v[i]>=0)
     {
       maximum_so_far=max(maximum_so_far*v[i],v[i]);
       minimum_so_far=min(minimum_so_far*v[i],v[i]);
     }
     else
     {
       ll product1=minimum_so_far*v[i];  /// Because maximum_so_far=max(minimum_so_far*v[i],v[i])
       ll product2=maximum_so_far*v[i];  /// And minimum_so_far=min(maximum_so_far*v[i],v[i])
       maximum_so_far=max(product1,v[i]); /// So changing max before assigning to min will produce wrong output
       minimum_so_far=min(product2,v[i]);
     }
     //cout<<"Max so far "<<maximum_so_far<<" "<<"Min so far "<<minimum_so_far<<" "<<"Global max "<<global_maximum<<endl;
     if(global_maximum<maximum_so_far)
     {
       global_maximum=maximum_so_far;
     }
   }
   cout<<global_maximum;
}
