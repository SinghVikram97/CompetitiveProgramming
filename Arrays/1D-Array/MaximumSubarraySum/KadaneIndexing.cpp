#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
  {
     cin>>v[i];
  }
  ll max_sum=v[0];
  ll cur_sum=v[0];
  int start=0,end=0,s=0;
  for(int i=1;i<n;i++)
  {
     cur_sum=cur_sum+v[i];
     //cout<<cur_sum<<endl;
     if(cur_sum>max_sum)         /// This if before below if to handle all -ve numbers -2 -1 -3 = -1
     {
       start=s;
       end=i;                    
       max_sum=cur_sum;
     }
     if(cur_sum<=0)              /// If cur_sum becomes less than equal to zero it means no fyada in taking it because it will already reduce the coming nos sum
     {
       s=i+1;
       cur_sum=0;
     }
  }
  cout<<"Maximum sum is "<<max_sum<<endl;
  cout<<"Subarray from "<<start<<" to "<<end;
}
