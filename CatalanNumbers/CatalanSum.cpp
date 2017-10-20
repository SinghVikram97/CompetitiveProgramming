https://www.hackerrank.com/contests/walmart-codesprint-algo/challenges/popsicle-stick-mountains/submissions/code/1303742215

#include<bits/stdc++.h>
using namespace std;
unsigned long long int m=1000000007;
unsigned long long int dp[4005]={0};
unsigned long long int preSum[4005];
unsigned long long int catalan(unsigned long long int n)
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
        unsigned long long int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=(ans+((catalan(i-1)%m)*(catalan(n-i)%m))%m)%m;
        }
        dp[n]=ans;
        return dp[n];
    }
}
void preComputeSum()
{
    unsigned long long int sum=0;
    /// Sum is from 1st catalan no upto n/2;
    for(int i=1;i<=4000;i++)
    {
        sum=((sum%m)+(catalan(i)%m))%m;
        preSum[i]=sum;
    }
}
int main()
{
  dp[0]=1;
  dp[1]=1;
  preComputeSum();
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      /// Sum upto n/2 catalan no precompute this
      /// preSum[i] is sum upto ith catalan no
      cout<<preSum[n/2]<<endl;
  }
}
