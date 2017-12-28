#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll lcs(string a,string b,int i,int j)
{
   int n=a.length();
   int m=b.length();
   ll dp[n][m];           /// dp[i][j] means lcs upto ith index of a and jth index of b
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<m;j++)
     {
       if(a[i]==b[j])
       {
          if(i-1<0 || j-1<0)
          {
            dp[i][j]=1;
          }
          else
          {
            dp[i][j]=1+dp[i-1][j-1];
          }
       }
       else if(a[i]!=b[j])         /// If both charaters not equal can delete either from string a or string b
       {
         if(i-1<0 && j-1<0)
         {
           dp[i][j]=0;
         }
         else if(i-1<0)
         {
           dp[i][j]=dp[i][j-1];    /// Delete from b or move j one step backward
         }
         else if(j-1<0)
         {
           dp[i][j]=dp[i-1][j];    /// Delete from a or move i one step backward
         }
         else
         {
           dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
         }
       }
     }
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
   }
   return dp[n-1][m-1];
}
int main()
{
   string a,b;
   cin>>a>>b;
   cout<<lcs(a,b,0,0);
}
