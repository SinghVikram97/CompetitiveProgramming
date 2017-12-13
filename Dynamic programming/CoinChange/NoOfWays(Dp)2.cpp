/// Order doesn't matters
#include<bits/stdc++.h>
using namespace std;
int dp[255][55];  /// dp[current_value][index]
int number_of_ways(int total_value,vector<int> coins,int current_value,int index)
{

   if(current_value==total_value)
   {
     dp[current_value][index]=1;
     return 1; /// Sucessful
   }
   else if(current_value>total_value)
   {
      return 0; /// Unsucessful
   }
   else if(index==coins.size())
   {
     dp[current_value][index]=0;
     return 0; /// Run out of coins
   }
   /// Le skte ho ya fir nhi le skte
   if(dp[current_value][index]==-1)
   {
     dp[current_value][index]=number_of_ways(total_value,coins,current_value+coins[index],index)+number_of_ways(total_value,coins,current_value,index+1);
   }
   return dp[current_value][index];   
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    vector<int> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }
    cout<<number_of_ways(n,v,0,0)<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
