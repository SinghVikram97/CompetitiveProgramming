/// Order doesn't matters
#include<bits/stdc++.h>
using namespace std;
int dp[255][55]; /// Total_value and index
/// dp[total_value][index] denotes ways to give total_value using coins upto that index?????? No
/// dp[i][j] number of ways to get total_value i using coins from index j to last index
int number_of_ways(int total_value,vector<int> coins,int index)
{
   if(total_value<0)  /// Imp condition
   {
       return 0;
   }
   else if(total_value==0)
   {
     dp[total_value][index]=1;
     return 1; /// Sucessful
   }
   else if(total_value>0 && index==coins.size())  /// Run out of coins but not money
   {
     return 0; /// Unsucessful
   }
   else
   {
     /// Le skte ho ya nhi le skte
     if(dp[total_value][index]==-1)
     {
        dp[total_value][index]=number_of_ways(total_value-coins[index],coins,index)+number_of_ways(total_value,coins,index+1);
     }
     return dp[total_value][index];
   }

}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)  /// From 0 not 1
    {
        for(int j=0;j<=m;j++) /// From 0 not 1
        {
            dp[i][j]=-1;
        }
    }
    vector<int> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }
    cout<<number_of_ways(n,v,0)<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
