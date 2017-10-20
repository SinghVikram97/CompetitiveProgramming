#include<bits/stdc++.h>
using namespace std;
int dp[100]={0};
int catalan(int n)
{
    if(n==0 || n==1)
    {
       return dp[n];
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    else
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=catalan(i-1)*catalan(n-i);
        }
        dp[n]=ans;
        return dp[n];
    }
}
int main()
{
  dp[0]=1;
  dp[1]=1;
  for(int i=0;i<5;i++)
  {
      cout<<catalan(i)<<" ";
  }
}
