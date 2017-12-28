https://hack.codingblocks.com/contests/c/1001/646
#include<bits/stdc++.h>
using namespace std;
int minimum_cost(int n,int x,int y,int z)
{
   int dp[n+1]; /// dp[i]denotes minimum cost to reach ith position
   dp[1]=0;
   for(int i=2;i<=n;i++)
   {
       if(i%2==0)
       {
         /// Can reach from i/2 or i-1
         dp[i]=min(x+dp[i/2],y+dp[i-1]);
       }
       else
       {
         /// Can reach from i+1 or i-1
         /// To reach i+1 we can reach there from (i+1)/2 as (i+1) is even
         /// We can reach i+1 from i also but since we haven't reached i yet so this option not valid
         dp[i]=min(y+dp[i-1],x+dp[(i+1)/2]+z);
       }
   }
   return dp[n];
}
int main()
{
   int n;
   cin>>n;
   int x,y,z;
   cin>>x>>y>>z;
   cout<<minimum_cost(n,x,y,z);
}
