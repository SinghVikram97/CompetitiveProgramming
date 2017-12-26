2,3,5,4,1 - 55
2,3,5,1,4 - 50
#include<bits/stdc++.h>
using namespace std;
int maximum_cost(vector<int> v,int beg,int end,int day)
{
   if(beg>end)
   {
     return 0;
   }
   else
   {
     int op1=(day*v[beg])+maximum_cost(v,beg+1,end,day+1);
     int op2=(day*v[end])+maximum_cost(v,beg,end-1,day+1);
     return max(op1,op2);
   }
}
int main()
{
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++)
   {
     cin>>v[i];
   }
   cout<<maximum_cost(v,0,n-1,1);
}
