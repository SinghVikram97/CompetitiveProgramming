#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[105][105];
vector<ll> prefix_sum;
ll csum(int i,int j)
{
   /// Sum from i to j th index
  return ((prefix_sum[j+1]%100)-(prefix_sum[i]%100)+100)%100;
}
ll minimum_smoke(vector<int> mixture,int number_of_mixtures,int i,int j)
{
   //cout<<i<<" "<<j<<endl;
   /// If only one mixture left no smoke will be generated
   if(i==j)
   {
     return 0;
   }
   if(i>j)
   {
     return INT_MAX;
   }
   if(dp[i][j]==-1)
   {
      /// Function returns minimum smoke while mixing from i to j mixtures
      /// 2 partions 1st from i to k and 2nd from k+1 to j
      /// value of k from 0 to j-
      ll result=INT_MAX;
      for(int k=i;k<=j-1;k++)
      {
        result=min(result,minimum_smoke(mixture,number_of_mixtures,i,k)+minimum_smoke(mixture,number_of_mixtures,k+1,j)+(csum(i,k)*csum(k+1,j)));
      }
      dp[i][j]=result;
   }
   return dp[i][j];
}
int main()
{
  int number_of_mixtures;
  while(scanf("%d",&number_of_mixtures)!=EOF)
  {
     for(int i=0;i<105;i++)
     {
      for(int j=0;j<105;j++)
      {
         dp[i][j]=-1;
      }
     }
     vector<int> mixture(number_of_mixtures);
     for(int i=0;i<number_of_mixtures;i++)
     {
       cin>>mixture[i];
     }
     prefix_sum.push_back(0);
     for(int i=0;i<number_of_mixtures;i++)
     {
        prefix_sum.push_back((prefix_sum[i]%100)+(mixture[i]%100)%100);
     }
     cout<<minimum_smoke(mixture,number_of_mixtures,0,number_of_mixtures-1)<<endl;
     prefix_sum.clear();
  }
}
