#include<bits/stdc++.h>
using namespace std;
unsigned long long int dp[1006][1006]={0};
int main()
{
    dp[0][0]=1;
    for(int i=1;i<=1005;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i)
                dp[i][j]=1;
            else
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%1000000000;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            cout<<dp[n][i]<<" ";
        }
        cout<<endl;
    }
}
