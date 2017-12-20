#include<bits/stdc++.h>
using namespace std;
int maximum_value(int capacity,vector<int> size,vector<int> value)
{ 
   int dp[capacity+1]; /// dp[i] denotes maximum value stored by knapsack if its capacity is 'i'
   dp[0]=0; /// 0 capacity means it can't store anything
   for(int i=1;i<=capacity;i++)
   {
     dp[i]=0; /// Store minimum as we want to store maximum in it
   }
   for(int i=1;i<=capacity;i++)
   {
     int current_value;
     /// We can choose any one item 
     for(int j=0;j<value.size();j++)
     { 
         /// Subject to condition
         if(size[j]<=i)
         {
            current_value=value[j]+dp[i-size[j]];
            if(current_value>dp[i])
            {
              dp[i]=current_value;
            }
         }
     }
   }
   return dp[capacity];
}
int main()
{
   int no_of_items,capacity;
   cin>>no_of_items>>capacity;
   vector<int> size(no_of_items);
   vector<int> value(no_of_items);
   for(int i=0;i<no_of_items;i++)
   {
     cin>>size[i];
   }
   for(int i=0;i<no_of_items;i++)
   {
     cin>>value[i];
   }
   cout<<maximum_value(capacity,size,value);
}
