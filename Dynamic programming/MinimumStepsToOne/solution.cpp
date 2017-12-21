http://www.spoj.com/submit/MST1/
Can precompute and store answers in array also 
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll dp[20000005];
ll steps(ll n)
{
   if(n==1)
   {
     return 0;
   }
   if(dp[n]==-1)
   {
     /// At each point we can take 3 steps
     ll option1=1+steps(n-1);
     if(n%2==0)
     {
       option1=min(option1,1+steps(n/2));
     }
     if(n%3==0)
     {
       option1=min(option1,1+steps(n/3));
     }
     dp[n]=option1;
    }
    return dp[n];
}
int main()
{
   std::ios::sync_with_stdio(false);
   for(int i=0;i<=20000004;i++)
   {
     dp[i]=-1;
   }
   int t;
   cin>>t;
   int caseNo=0;
   while(t--)
   {
       caseNo++;
       ll n;
       cin>>n;
       cout<<"Case "<<caseNo<<": "<<steps(n)<<endl;
   }
}
