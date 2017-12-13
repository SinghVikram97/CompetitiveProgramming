#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(m+1); /// 1 based indexing
    for(int i=1;i<=m;i++)
    {
        cin>>v[i];
    }
    int dp[255][55]; /// dp[i][j] denotes ways to give change equal to i using first j coins
    /// so dp[n][m] is our answer
    /// if amount=0 number of ways is 1
    for(int j=0;j<=m;j++)
    {
       dp[0][j]=1;
    }
    /// if coins=0 number of ways is 0
    for(int i=0;i<=n;i++)
    {
        if(i!=0)  /// if dp[0][0]=1 as if amount=0 and coins=0 1 ways still
        {
            dp[i][0]=0;
        }
    }
    /// Calculating ans
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            /// Le skte hai ya nhi
            if(i-v[j]<0) /// Amount less than 0 so 0 ways
            {
              dp[i][j]=dp[i][j-1];  /// As j-1 was there so 1 based indexing for coins
            }
            else
            {
                dp[i][j]=dp[i][j-1]+dp[i-v[j]][j];
                /// nhi le skte ya le skte hai j wale ko(amount less by v[j])
            }
        }
    }
    cout<<dp[n][m];

}
