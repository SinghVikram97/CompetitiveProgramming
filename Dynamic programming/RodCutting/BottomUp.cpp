#include<bits/stdc++.h>
using namespace std;
int maximum_cost(int length_of_rod,vector<int> prices)
{
    int dp[length_of_rod+1];  /// dp[i] contains maximum cost if length of rod is i
    dp[0]=0;
    for(int i=1;i<=length_of_rod;i++)
    {
        dp[i]=-1;
        /// We can come to dp[i] from dp[i-1],dp[i-2],dp[i-3]......dp[0](If we sell entire rod)
        /// We can take piece of length=1,2,3,....length_of_rod and calculate for remaining length
        for(int j=1;j<=i;j++)
        {
           dp[i]=max(dp[i],prices[j]+dp[i-j]);
        }
    }
    return dp[length_of_rod];
}
int main()
{
   int length_of_rod;
   cin>>length_of_rod;
   vector<int> prices(length_of_rod+1); /// 1 based indexing
   for(int i=1;i<=length_of_rod;i++)
   {
     cin>>prices[i];
   }
   cout<<maximum_cost(length_of_rod,prices);
}
