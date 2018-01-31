#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
   int n;
   cin>>n;
   vector<ll> v(n);
   for(int i=0;i<n;i++)
   {
       cin>>v[i];
   }
   ll smallest;
   ll index;
   /// Select smallest element in each iteration and bring it to front
   /// If we put n-1 elements in their places then array will be sorted
   for(int i=0;i<n-1;i++)
   {
       smallest=INT_MAX;
       /// Swap smallest element with element at ith position
       /// Elements sorted upto i-1
       /// So start from i
       for(int j=i;j<n;j++)
       {
           if(v[j]<smallest)
           {
               smallest=v[j];
               index=j;
           }
       }
       swap(v[i],v[index]);
   }
   for(int i=0;i<n;i++)
   {
       cout<<v[i]<<" ";
   }
}
