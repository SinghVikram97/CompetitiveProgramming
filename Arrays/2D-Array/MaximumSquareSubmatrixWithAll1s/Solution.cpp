#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  int mat[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
       cin>>mat[i][j];
    }
  }
  int ans=INT_MIN;
  int table[n][m];                  /// Table[i][j] represents size of square submatrix with (i,j) th element as its
  for(int i=0;i<n;i++)              /// Bottom right element
  {
    for(int j=0;j<m;j++)
    {
      if(i==0 || j==0)                 /// Can't be bottom right element of any matrix except 1 if element=1
      {
         table[i][j]=mat[i][j];
      }
      else
      {
         if(mat[i][j]==0)
         {
           table[i][j]=0;
         }
         else
         {
           table[i][j]=min(table[i-1][j],min(table[i-1][j-1],table[i][j-1]))+1;   /// Extend the size of square by 1
           if(table[i][j]>ans)
            ans=table[i][j];
         }
      }
    }
  }
  cout<<endl;
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
     {
       cout<<table[i][j]<<" ";
     }
     cout<<endl;
  }
  cout<<endl;
  cout<<ans;
}
