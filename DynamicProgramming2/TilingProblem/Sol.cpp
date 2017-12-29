#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
/// dp[i]=dp[i-1]+dp[i-2]
/// We can place tile vertically so we have to file remaining i-1
/// Or we can place tile horizontally but we have to place 2 tiles horizontally one above other so i-2
int main()
{
   int n;
   cin>>n;
   ll a=1;
   ll b=2;
   if(n==1)
    cout<<a;
   else if(n==2)
    cout<<b;
   else
   {
     ll c;
     for(int i=3;i<=n;i++)
     {
        c=(b%m+a%m)%m;
        a=b%m;
        b=c%m;
     }
     cout<<c%m;
   }
   
}
