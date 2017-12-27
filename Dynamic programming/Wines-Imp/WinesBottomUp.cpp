///2,3,5,4,1 - 55
///2,3,5,1,4 - 50
/// 2,3,5-23
#include<bits/stdc++.h>
using namespace std;
/// We can reduce state functions by calculating days from beg and end
/// And not passing days
/// Earlier we had 3 variables-3D dp
/// Now only 2 -2D dp
int maximum_cost(vector<int> v,int n)
{
   int dp[n][n]; /// Our ans will be in dp[0][n-1]
   /// dp[i][j] is maximum cost if wines between i and j th index
   /// if i>j fill 0 as no wine (This portion is below main diagonal)
   ///     i+1,j<--i,j
   ///              |
   ///              |
   ///             i,j-1
   for(int i=n-1;i>=0;i--)
   {
     for(int j=0;j<n;j++)
     {
       if(i>j)
       {
         dp[i][j]=0;
       }
       else
       {
         int year=(n)-(j-i+1)+1;
         if(i+1<n && j-1>=0)
         {
            dp[i][j]=max(year*v[i]+dp[i+1][j],year*v[j]+dp[i][j-1]);
         }
         else if(i+1>=n)
         {
           dp[i][j]=year*v[j]+dp[i][j-1];
         }
         else if(j-1<0)
         {
           dp[i][j]=year*v[i]+dp[i+1][j];
         }
       }
     }
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
   }
   cout<<endl;
   return dp[0][n-1];
}
int main()
{
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++)
   {
     cin>>v[i];
   }
   cout<<maximum_cost(v,n);
}
