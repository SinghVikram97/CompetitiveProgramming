#include<bits/stdc++.h>
using namespace std;
int calculate(int amount,vector<int> coins)
{
   if(amount==0)
   {
     return 1; /// If sucessful increase in our answer by 1
   }
   /// Can pick any coin
   int ways=0;
   for(int i=0;i<coins.size();i++)
   {
     /// Pick a coin and calculate ways to make amount-value of that coin
     /// Can only pick a coin if
     if(coins[i]<=amount)
     {
       ways=ways+calculate(amount-coins[i],coins);
     }
   }
   return ways;
}
int main()
{
    int amount,no_of_coins;
    cin>>amount>>no_of_coins;
    vector<int> coins(no_of_coins);
    for(int i=0;i<no_of_coins;i++)
    {
      cin>>coins[i];
    }
    cout<<calculate(amount,coins);
}
