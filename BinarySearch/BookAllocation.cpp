#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool can(vector<ll> v,int m,long long mid)
{
  ll n=v.size();
  ll i=0,students=0;
  ll sum=0;
  while(i<n && students<m)
  {
      sum=0;
      while(i<n && sum+v[i]<=mid)
      {
          sum=sum+v[i];
          i++;
      }
      students++;
  }  
  if(i==n)   /// Wrong answer if we check if(student==m && i==n)    Read this https://stackoverflow.com/questions/36720228/allocate-minimum-number-of-pages-to-each-student
   {
      return true;
  }
  return false;
}
int main()
{
  ll n,m;
  cin>>n>>m;
  vector<ll> v(n);
  ll sum=0;
  for(ll i=0;i<n;i++)
  {
      cin>>v[i];
      sum=sum+v[i];
  }
  sort(v.begin(),v.end());
  ll start=v[n-1];
  ll end=sum;
  ll ans;
  while(start<=end)
  {
      ll mid=(start)+(end-start)/2;
      if(can(v,m,mid))
      {
          ans=mid;
          /// Chota karne ki koshish karo
          end=mid-1;
      }
      else /// Thoda bda karo itna chota possible nhi hai
      {
          start=mid+1;
      }
  }
   cout<<ans;
}
