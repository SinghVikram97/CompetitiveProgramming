/// 3
/// 1 7 10
///  15
#include<bits/stdc++.h>
using namespace std;
int min_coins(vector<int> coins,int amount)
{
  /// Base cases
   if(amount==0) /// Zero ways to give 0 ruppees
   {
     return 0;
   }
   else if(amount<0)
   {
     return INT_MAX;
   }
  /// Can pick any one coin
  int ways=INT_MAX,current_ways;
  for(int i=0;i<coins.size();i++)
  {
    /// Pick ith coin and calculate no of ways for amount-coins[i]
    current_ways=min_coins(coins,amount-coins[i]);
    /// If less coins required than previous calculated update
    if(current_ways<ways)
    {
      ways=current_ways;
    }
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
