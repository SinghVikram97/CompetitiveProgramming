#include<bits/stdc++.h>
using namespace std;
int minimum=INT_MAX;
void min_coins(vector<int> coins,int amount,int current_amount,int index,int total_coins)
{
    //cout<<index<<endl;
  /// Base case
  if(current_amount==amount)
  {
    if(total_coins<minimum)
    {
      minimum=total_coins;
    }
    return;
  }
  else if(current_amount>amount)  /// Exceed
  {
    return;
  }
  else if(index==coins.size())  /// Run out of money
  {
    return;
  }
  /// Given coin ko le skte ho ya nhi
  /// Lelo
  min_coins(coins,amount,current_amount+coins[index],index,total_coins+1); /// Not index+1
  /// Mat lo
  min_coins(coins,amount,current_amount,index+1,total_coins);
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
  min_coins(coins,amount,0,0,0);
  if(minimum==INT_MAX)
  {
      cout<<"Can't give change";
  }
  else
  {
      cout<<minimum;
  }

}
