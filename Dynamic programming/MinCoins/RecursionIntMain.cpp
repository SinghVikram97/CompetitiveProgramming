/// 3
/// 1 7 10
///  15
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
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
   /// Le lo
   int ways1=min_coins(coins,amount-coins[index],index);
   /// Na lo
   int ways2=min_coins(coins,amount,index+1);
   return min(ways1+1,ways2);
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
