#include<bits/stdc++.h>
using namespace std;
bitset<100> column,diagonal_difference,diagonal_sum;
int countQueen=0;
void solve(int n,int i)
{
  if(i==n)
  {
    countQueen++;
    return;
  }
  for(int j=0;j<n;j++)
  {
    /// If column diagonal1 and diagonal2 not filled we can place at row,j position
    /// column i information stored at ith index
    /// **************
    /// diagonal_difference from -(n-1) to (n-1)
    /// So 0th index is -(n-1) 1st index -(n-1)+1
    /// Store information of i,j at (i-j)+(n-1)
    /// so if difference -(n-1) then store at -(n-1)+(n-1)=0
    /// **************
    /// diagonal sum from 0 to 2*(n-1)
    if(column[j]==0 && diagonal_difference[i-j+(n-1)]==0 && diagonal_sum[i+j]==0) /// Kar skte ho place
    {
       column[j]=1;
       diagonal_difference[i-j+(n-1)]=1;
       diagonal_sum[i+j]=1;
       solve(n,i+1);
       /// Backtrack
       column[j]=0;                        
       diagonal_difference[i-j+(n-1)]=0;  /// Can't place these 3 statements outside wrong ans for n=3
       diagonal_sum[i+j]=0;
    }
  }
  return;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  cin>>n;
  solve(n,0);
  cout<<countQueen;
}
