#include<bits/stdc++.h>
using namespace std;
int maximum_value(int capacity,vector<int> size,vector<int> value,int no_of_items)
{

     int dp[capacity+1][no_of_items+1];
     /// If capacity is zero so zero value
     for(int j=0;j<=no_of_items;j++)
     {
        dp[0][j]=0;
     }
     /// If no items are there we can't put anything in knapsack so value zero
     for(int i=0;i<=capacity;i++)
     {
       dp[i][0]=0;
     }
     /// Dp[i][j] represents maximum value that can be obtained if capacity of knapsack is i
     /// And there are j items
     /// Now if we are at jth item we have 2 options 
     /// 1. We can select it so answer can be value[j]+DP[i-size[j]][j-1] /// Remaining amount with remaining items Repetion not allowed
     /// 2. We don't select it so answer can be DP[i][j-1]
     for(int i=1;i<=capacity;i++)
     {
      for(int j=1;j<=no_of_items;j++)
      {
         /// 2 options
         int option1=-1,option2=-1;
         ///1. Select only if
         if(size[j]<=i)
         { 
             option1=value[j]+dp[i-size[j]][j-1];
         }
         /// 2. Don't select
         option2=dp[i][j-1];
         dp[i][j]=max(option1,option2);
      }
     }
     return dp[capacity][no_of_items];
}
int main()
{
   int capacity,no_of_items;
   cin>>capacity>>no_of_items;
   vector<int> size(no_of_items+1);   /// 1 based indexing
   vector<int> value(no_of_items+1);  /// 1 based indexing
   for(int i=1;i<=no_of_items;i++)
   {
     cin>>size[i]>>value[i];
   }
   cout<<maximum_value(capacity,size,value,no_of_items); /// Maximum sum of values just smaller or equal to capacity
}
