http://codeforces.com/contest/456/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[100005];
int main()
{
   int n;
   cin>>n;
   vector<int> v(n);
   int max_no=-1;
   for(int i=0;i<n;i++)
   {
    cin>>v[i];
    max_no=max(max_no,v[i]);
   }
   map<int, long long int> freq;
   for(int i=0;i<n;i++)
   {
       freq[v[i]]++;
   }
   dp[0]=0;
   for(int i=1;i<=max_no;i++)
   {
     if(i==1)
     {
       dp[i]=max(freq[i]*i,dp[i-1]);
     }
     else
     {
       dp[i]=max((freq[i]*i)+dp[i-2],dp[i-1]);
     }
   }
   cout<<dp[max_no];
}
