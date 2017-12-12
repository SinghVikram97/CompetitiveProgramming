/// Order doesn't matters
#include<bits/stdc++.h>
using namespace std;
int number_of_ways(int total_value,vector<int> coins,int index)
{
    if(total_value>0 && index==coins.size()) /// Run out of coins but not money
    {
        return 0;
    }
    else if(total_value==0)
    {
        return 1;
    }
    else
    {
        int ways=0;
        while(total_value>=0)
        {
            /// 0 coins of current coin
           ways=ways+number_of_ways(total_value,coins,index+1);
           total_value=total_value-coins[index];
        }
        return ways;
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
