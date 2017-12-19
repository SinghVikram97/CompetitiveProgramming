/// 3
/// 1 7 10
///  15
#include<bits/stdc++.h>
using namespace std;
#define max 1000000
/// Can't use INT_MAX as 1+INT_MAX returns negative value
int dp[10000];
int min_coins(vector<int> coins,int amount)
{
    //cout<<amount<<endl;
  /// Base cases
   if(amount==0) /// Zero ways to give 0 ruppees             /// 15,8,1,0
   {
     return 0;
   }
   else if(amount<0)
   {
     return max;
   }
    if(dp[amount]==-1)
    {
        /// Can pick any one coin
        int ways=max,current_ways;
        for(int i=0; i<coins.size(); i++)
        {
            /// Pick ith coin and calculate no of ways for amount-coins[i]
            current_ways=1+min_coins(coins,amount-coins[i]);
            /// If less coins required than previous calculated update
            if(current_ways<ways)
            {
                ways=current_ways;
            }
        }
        dp[amount]=ways;
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
  for(int i=0;i<=amount;i++)
  {
    dp[i]=-1;
  }
  cout<<min_coins(coins,amount);
}
