/// 3
/// 1 7 10
///  15
#include<bits/stdc++.h>
using namespace std;
#define max 1000000
int min_coins(vector<int> coins,int amount,int n)
{
   /// n represents no of coins
   int dp[n+1][amount+1];
   /// dp[i][j]=min of dp[i][j-coins[i]] and dp[i-1][j]
   /// dp[i][j]=min of dp[i][j-coins[i]] and dp[i+1][j] is wrong
   /// In bottom up we have to use previous answers so always -1
   /// Answer in dp[n][amount]  /// dp[i][j] represents min_coins for making amount j using coins upto ith index
   for(int i=1;i<=n;i++)  /// If amount=0 but not is case of dp[0][0]
   {
      dp[i][0]=0;
   }
   for(int j=0;j<=amount;j++) /// Making Amount using 0 coins is impossible
   {
      dp[0][j]=max;
   }
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=amount;j++)
    {
      dp[i][j]=min(dp[i][j-coins[i]]+1,dp[i-1][j]);
    }
   }
   return dp[n][amount];
}
int main()
{
  int n;   /// Number of coins of different denominations
  cin>>n;
  vector<int> coins(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>coins[i];
  }
  int amount;
  cin>>amount;
  cout<<min_coins(coins,amount,n);
}
