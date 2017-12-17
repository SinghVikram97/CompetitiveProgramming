/// 3
/// 1 7 10
///  15
#include<bits/stdc++.h>
using namespace std;
int min_coins(vector<int> coins,int amount,int current_amount,int index)
{
   /// Base case
   if(current_amount==amount)
   {
     return 0;   /// Recursion tree is 0-7-14-15 /// 4 nodes and 3 connects
   }
   else if(current_amount>amount)
   {
     return 1000005;
   }
   else if(index==coins.size())
   {
     return 1000005;
   }
   /// Lelo ya mat lo
   /// Leke minimum coins
   int min1=min_coins(coins,amount,current_amount+coins[index],index);
   /// Na leke
   int min2=min_coins(coins,amount,current_amount,index+1);
   /// Min1 mein add 1 kyunki usme ek coin leliya
   return min(min1+1,min2);
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
  int coinsNeeded=min_coins(coins,amount,0,0);
  if(coinsNeeded==1000005)
  {
      cout<<"Can't give change";
  }
  else
  {
      cout<<coinsNeeded;
  }
}
