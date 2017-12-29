#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     cin>>n;
     ll dp[n+1];        /// ways n people can remain single or pair up
     dp[1]=1;          
     dp[2]=2;
     for(int i=3;i<=n;i++)
     {
       dp[i]=dp[i-1]+(i-1)*dp[i-2];      /// Can remain single or pair with any one of remaining n-1 persons
     }
     cout<<dp[n]<<endl;
   }
}
