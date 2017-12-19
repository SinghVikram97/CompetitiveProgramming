/// 3
/// 1 7 10
///  15
#include<bits/stdc++.h>
using namespace std;
#define max 1000000
/// Can't use INT_MAX as 1+INT_MAX returns negative value
int min_coins(vector<int> coins,int amount)
{
   int dp[amount+1]; /// dp[i] is min_coins for amount i
   dp[0]=0; /// 0 ways to give 0 ruppees
   int ways=max;
   int current_ways;
   for(int i=1;i<=amount;i++)
   {
      /// Koi bhi ek coin pick kar skte hao
      for(int i=0;i<coins.size();i++)
      {
          /// Can pick a coin if and only if amount-coins[i]>=0
          /// else dp[amount-coins[i]] out of index error
          if(amount-coins[i]>=0)
          {
            current_ways=1+dp[amount-coins[i]];
            if(current_ways<ways)
            {
              dp[amount]=current_ways;
            }
          }
      }
   }
   return dp[amount];

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
