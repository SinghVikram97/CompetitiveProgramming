https://www.geeksforgeeks.org/printing-longest-common-subsequence/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll lcs(string a,string b,int i,int j)
{
   int n=a.length();
   int m=b.length();
   ll dp[n][m];
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
       else if(a[i]!=b[j])
       {
         if(i-1<0 && j-1<0)
         {
           dp[i][j]=0;
         }
         else if(i-1<0)
         {
           dp[i][j]=dp[i][j-1];
         }
         else if(j-1<0)
         {
           dp[i][j]=dp[i-1][j];
         }
         else
         {
           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
         }
       }
     }
   }
   i=n-1,j=m-1;
   string ans="";
   while(i>=0 && j>=0)
   {
     if(a[i]==b[j])           /// Move diagonally upward and include current character in final ans
     {
       ans=a[i]+ans;
       i--;
       j--;
     }
     else                   /// If not equal move in direction of greater number
     {
       if(i-1>=0 && j-1>=0)
       {
          if(dp[i-1][j]>dp[i][j-1])
          {
             i--;
          }
          else
          {
             j--;
          }
       }
       else if(i-1<0)
       {
         j--;
       }
       else if(j-1<0)
       {
         i--;
       }
     }
   }
   cout<<ans<<endl;
   return 0;
}
int main()
{
   string a,b;
   cin>>a>>b;
   lcs(a,b,0,0);
}
