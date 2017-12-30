///-3 3 19 7
/// Wrong for -3 3
/// Wrong for all -ve numbers if reverse order of i conditions
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
  ll max_sum=INT_MIN;
  ll cur_sum=0;
  int start,end;
  for(int i=0;i<n;i++)
  {
    /// cur_sum contains sum upto previous index
    /// if it is negative or 0 so use of expanding our subarray
    if(cur_sum<=0)
    {
       cur_sum=v[i];  /// Start from this element
       start=i;
    }
    else
    {
       cur_sum=cur_sum+v[i];  /// Expand our subarray
    }
    if(cur_sum>max_sum)     /// Compare with maximum sum at each step after updating
    {
       max_sum=cur_sum;
       end=i;
    }
  }
  cout<<"Maximum sum is "<<max_sum<<endl;
  cout<<"Subarray with maximum sum is from "<<start<<" to "<<end;
}
