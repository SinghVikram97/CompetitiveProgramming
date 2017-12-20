#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int maximum_value(int capacity,vector<int> size,vector<int> value,int index)
{
   /// Base cases
   if(capacity==0)
   {
     return 0; /// Capacity zero hai toh item kuch nhi dal skte toh value 0
   }
   else if(index==value.size())
   {
     return 0; /// Koi item nhi hai dalne ko toh value 0 rehega knapsack mein
   }
   if(dp[capacity][index]==-1)
   {
        /// 2 options select kro ya mat kro
   /// 1. Select tbhi kar skte ho
   int option1=-1,option2=-1;
   if(size[index]<=capacity)
   {
     option1=value[index]+maximum_value(capacity-size[index],size,value,index); /// Not index+1 as repetiton allowed
   }
   /// 2. Select mat kro
   option2=maximum_value(capacity,size,value,index+1);
   dp[capacity][index]=max(option1,option2);
   }
    return dp[capacity][index];
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
     for(int j=0;j<=no_of_items;j++)
     {
       dp[i][j]=-1;
     }
   }
   cout<<maximum_value(capacity,size,value,0);
}
