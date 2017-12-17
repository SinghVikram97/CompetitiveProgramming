/// 3
/// 1 7 10
///  15
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int dp[1000][1000]; /// 2 variables amount and index
/// dp[i][j] is min_coins required for amount i using index from j to n-1
int min_coins(vector<int> coins,int amount,int index)
{
   /// Base case
   if(amount==0)  /// Recursion tree 15-8-1-0  /// Nodes 4 connects 3
   {
      return 0; /// Amount 0 hai toh 0 ways;
   }
   else if(amount<0)
   {
     return MAX;
   }
   else if(index==coins.size())
   {
     return MAX;
   }
   if(dp[amount][index]==-1)
   {
      /// Le lo
      int ways1=min_coins(coins,amount-coins[index],index);
      /// Na lo
      int ways2=min_coins(coins,amount,index+1);
      dp[amount][index]=min(ways1+1,ways2);
   }
   return dp[amount][index];
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
    for(int j=0;j<=n;j++)
    {
       dp[i][j]=-1;
    }
  }
  int coinsNeeded=min_coins(coins,amount,0);
  if(coinsNeeded==MAX)
  {
      cout<<"Can't give change";
  }
  else
  {
      cout<<coinsNeeded;
  }
}
