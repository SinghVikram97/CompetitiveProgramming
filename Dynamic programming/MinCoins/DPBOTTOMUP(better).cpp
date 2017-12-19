/// 3
/// 1 7 10
///  15
#include<bits/stdc++.h>
using namespace std;
#define max 100000
/// Can't use INT_MAX as 1+INT_MAX returns negative value
int min_coins(vector<int> coins,int amount)
{
   int dp[amount+1]; /// dp[i] is min_coins for amount i
   dp[0]=0; /// 0 ways to give 0 ruppees
   for(int i=1;i<=amount;i++)
   {
       dp[i]=max;  /// Assume sab mein abhi calculate nhi hua
   }
   int current_ways;
   for(int i=1;i<=amount;i++)
   {
      /// Koi bhi ek coin pick kar skte hao
      for(int j=0;j<coins.size();j++)
      {
          /// Can pick a coin if and only if amount-coins[i]>=0
          /// else dp[amount-coins[i]] out of index error
          if(i-coins[j]>=0)
          {
            current_ways=1+dp[i-coins[j]];
            if(current_ways<dp[i]) /// Agar is coin ko lene se kam coins lag rhe hai overall toh update value
            {
              dp[i]=current_ways;
            }
          }
      }
   }
   if(dp[amount]==max)
   {
       return -1;
   }
   else
   {
       return dp[amount];
   }
}
int main()
{
  int n;   /// Number of coins of different denominations
  cin>>n;
  vector<int> coins(n);
  for(int i=0;i<n;i++)
  {
    cin>>coins[i];
  }
  int amount;
  cin>>amount;
  cout<<min_coins(coins,amount);
}
