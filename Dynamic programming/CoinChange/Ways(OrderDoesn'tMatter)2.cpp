/// Order doesn't matters
#include<bits/stdc++.h>
using namespace std;
int number_of_ways(int total_value,vector<int> coins,int current_value,int index)
{

   if(current_value==total_value)
   {
     return 1; /// Sucessful
   }
   else if(current_value>total_value)
   {
      return 0; /// Unsucessful
   }
   else if(index==coins.size())
   {
     return 0; /// Run out of coins
   }
   /// Le skte ho ya fir nhi le skte
   return number_of_ways(total_value,coins,current_value+coins[index],index)+number_of_ways(total_value,coins,current_value,index+1);
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
    cout<<number_of_ways(n,v,0,0);
}
