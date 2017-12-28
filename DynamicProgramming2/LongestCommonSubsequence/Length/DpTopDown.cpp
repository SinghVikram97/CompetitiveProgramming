#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[1005][1005];
ll lcs(string a,string b,int i,int j)
{
   if(i==a.length())
   {
     return 0;
   }
   else if(j==b.length())
   {
     return 0;
   }
   if(dp[i][j]==-1)
   {
     if(a[i]!=b[j])                 /// If both charaters not equal can delete either from string a or string b
      {
        ll op1=lcs(a,b,i+1,j);      /// Delete from a
        ll op2=lcs(a,b,i,j+1);      /// Delete from b
        dp[i][j]=max(op1,op2);
      }
      else if(a[i]==b[j])           /// If both equal take it in the subsequence
      {
        ll ans=1+lcs(a,b,i+1,j+1);
        dp[i][j]=ans;
      }
   }
   return dp[i][j];
}
int main()
{
   for(int i=0;i<=1000;i++)
   {
     for(int j=0;j<=1000;j++)
     {
       dp[i][j]=-1;
     }
   }
   string a,b;
   cin>>a>>b;
   cout<<lcs(a,b,0,0);
}
