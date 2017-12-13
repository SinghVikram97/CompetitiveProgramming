/// Order doesn't matters
#include<bits/stdc++.h>
using namespace std;
int number_of_ways(int total_value,vector<int> coins,int index)
{
   if(total_value<0)  /// Imp condition
   {
       return 0;
   }
   else if(total_value==0)
   {
     return 1; /// Sucessful
   }
   else if(total_value>0 && index==coins.size())  /// Run out of coins but not money
   {
     return 0; /// Unsucessful
   }
   else
   {
     /// Le skte ho ya nhi le skte
     return number_of_ways(total_value-coins[index],coins,index)+number_of_ways(total_value,coins,index+1);
   }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }
    cout<<number_of_ways(n,v,0);
}

