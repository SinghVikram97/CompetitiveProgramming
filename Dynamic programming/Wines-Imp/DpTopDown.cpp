///2,3,5,4,1 - 55
///2,3,5,1,4 - 50
#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
/// We can reduce state functions by calculating days from beg and end
/// And not passing days
/// Earlier we had 3 variables-3D dp
/// Now only 2 -2D dp
int maximum_cost(vector<int> v,int beg,int end)
{
   if(beg>end)  /// No wine left
   {
     return 0;
   }
   else
   {
     /// 2 options take from beginging or end
     if(dp[beg][end]==-1)  /// dp[i][j] represents maximum cost of wines if wines between i and j th index
     {
       int remainingWines=end-beg+1;
       int day=v.size()-remainingWines+1; /// Total-remaining+1(Imp)
       int op1=(day*v[beg])+maximum_cost(v,beg+1,end);
       int op2=(day*v[end])+maximum_cost(v,beg,end-1);
       dp[beg][end]=max(op1,op2);
     }
     return dp[beg][end];
   }
}
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<=n;i++)
   {
     for(int j=0;j<=n;j++)
     {
       dp[i][j]=-1;
     }
   }
   vector<int> v(n);
   for(int i=0;i<n;i++)
   {
     cin>>v[i];
   }
   cout<<maximum_cost(v,0,n-1);
}
