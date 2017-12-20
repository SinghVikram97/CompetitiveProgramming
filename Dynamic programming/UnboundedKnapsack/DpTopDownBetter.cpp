#include<bits/stdc++.h>
using namespace std;
int dp[1005];
int maximum_value(int capacity,vector<int> size,vector<int> value)
{
   /// Base cases
   if(capacity==0)
   {
     return 0;
   }
   if(dp[capacity]==-1)  /// dp[i] is maximum value knapsack can store if its capacity is i
   {
     int finalAns=-1;
     int currentAns=-1;
     /// At any step we can select any one item (As repetition is allowed)
     for(int i=0;i<value.size();i++)
     {
      if(size[i]<=capacity)
      {
          /// Can be selected
          currentAns=value[i]+maximum_value(capacity-size[i],size,value);
          if(currentAns>finalAns)
         {
           finalAns=currentAns;
         }
      }
      dp[capacity]=finalAns;
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
   for(int i=0;i<=capacity;i++)
   {
     dp[i]=-1;
   }
   cout<<maximum_value(capacity,size,value);
}
