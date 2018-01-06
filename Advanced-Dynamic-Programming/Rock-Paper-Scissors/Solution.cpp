#include<bits/stdc++.h>
using namespace std;
double dp[105][105][105];
void set_dp()
{
  for(int i=0;i<105;i++)
  {
      for(int j=0;j<105;j++)
      {
          for(int k=0;k<105;k++)
          {
             dp[i][j][k]=-1.0;
          }
      }
  }
}
double probability_rock(int r,int s,int p)
{
   if(r==0 || s==0)
    return 0.0;
   if(p==0)
    return 1.0;

   if(dp[r][s][p]==-1.0)
   {
     double ans=0.0;
     double total=(r*s)+(p*r)+(p*s);
     ans=ans+probability_rock(r-1,s,p)*(double(r*p)/total);
     ans=ans+probability_rock(r,s,p-1)*(double(p*s)/total);
     ans=ans+probability_rock(r,s-1,p)*(double(r*s)/total);
     dp[r][s][p]=ans;
   }
   return dp[r][s][p];
}
double probability_scissor(int r,int s,int p)
{
   if(s==0 || p==0)    /// Fight possible only b/w rock and scissor if p==0
    return 0.0;
   if(r==0)            /// Fight possible only b/w scissor and paper
    return 1.0;
   if(dp[r][s][p]==-1.0)
   {
     double ans=0.0;
     double total=(r*s)+(p*r)+(p*s);
     ans=ans+probability_scissor(r-1,s,p)*(double(r*p)/total);
     ans=ans+probability_scissor(r,s,p-1)*(double(p*s)/total);
     ans=ans+probability_scissor(r,s-1,p)*(double(r*s)/total);
     dp[r][s][p]=ans;
   }
   return dp[r][s][p];
}
double probability_paper(int r,int s,int p)
{
   if(p==0 || r==0)      /// Fight only possible between paper and scissor if rock=0
    return 0.0;
   if(s==0)              /// Fight only possible between paper and rock
    return 1.0;
   if(dp[r][s][p]==-1.0)
   {
     double ans=0.0;
     double total=(r*s)+(p*r)+(p*s);
     ans=ans+probability_paper(r-1,s,p)*(double(r*p)/total);
     ans=ans+probability_paper(r,s,p-1)*(double(p*s)/total);
     ans=ans+probability_paper(r,s-1,p)*(double(r*s)/total);
     dp[r][s][p]=ans;
   }
   return dp[r][s][p];
}
int main()
{
    double t;
    cin>>t;
    while(t--)
    {
      int r,s,p;
      cin>>r>>s>>p;
      cout<<fixed<<setprecision(9);
      set_dp();
      cout<<probability_rock(r,s,p)<<" ";
      set_dp();
      cout<<probability_scissor(r,s,p)<<" ";
      set_dp();
      cout<<probability_paper(r,s,p)<<endl;
    }
}
