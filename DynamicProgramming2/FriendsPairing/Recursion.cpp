#include<bits/stdc++.h>
using namespace std;
int number_of_pairs(int n,vector<bool> v,int index)
{
  
  if(index==n+1)
  {
     return 1;
  }
  if(v[index]==false)                    /// Can take current no if not paired
  {
     v[index]=true;
     int ans=number_of_pairs(n,v,index+1);
     for(int i=1;i<=n;i++)              /// As it is false we can also pair it
     {
         if(v[i]==false)
         {
           v[i]=true;
           ans=ans+number_of_pairs(n,v,index+1);
           v[i]=false;
         }
     }                
     return ans;                    
  }
  else if(v[index]==true)
  {
       /// Can't do anything call on next
      int ans=number_of_pairs(n,v,index+1);
      return ans;
  }
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     cin>>n;
     vector<bool> v(n+1);
     cout<<number_of_pairs(n,v,1)<<endl;
   }
}
