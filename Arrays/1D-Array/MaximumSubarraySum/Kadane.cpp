///-3 3 19 7
/// Wrong for -3 3
/// -3 -2 -4 -1
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
  for(int i=0;i<n;i++)
  {
    /// cur_sum contains sum upto previous index
    /// if it is negative or 0 so use of expanding our subarray
    if(cur_sum<=0)
    {
       cur_sum=v[i];  /// Start from this element
    }
    else
    {
       cur_sum=cur_sum+v[i];  /// Expand our subarray
    }
    if(cur_sum>max_sum)     /// Compare with maximum sum at each step after updating
    {
       max_sum=cur_sum;
    }
  }
  cout<<max_sum;
}
