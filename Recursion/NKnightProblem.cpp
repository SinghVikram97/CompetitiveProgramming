#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int countK=0;
bool canPlace(int n,int row,int column)
{
  for(int i=row-2;i>=0;i--)
  {
    for(int j=column+1;j<n;j++)
    {
      if(a[i][j]==1)
      {
        return false;
      }
    }
  }
  for(int i=row-2;i>=0;i--)
  {
    for(int j=column-1;j>=0;j--)
    {
      if(a[i][j]==1)
      {
        return false;
      }
    }
  }
  for(int i=row+2;i<n;i++)
  {
    for(int j=column+1;j<n;j++)
    {
      if(a[i][j]==1)
      {
        return false;
      }
    }
  }
  for(int i=row+2;i<n;i++)
  {
    for(int j=column-1;j>=0;j--)
    {
      if(a[i][j]==1)
      {
        return false;
      }
    }
  }
  for(int i=row-1;i>=0;i--)
  {
    for(int j=row-2;j>=0;j--)
    {
      if(a[i][j]==1)
      {
        return false;
      }
    }
  }
  for(int i=row-1;i>=0;i--)
  {
    for(int j=row+2;j<n;j++)
    {
      if(a[i][j]==1)
      {
        return false;
      }
    }
  }
  for(int i=row+1;i<n;i++)
  {
    for(int j=row-2;j>=0;j--)
    {
      if(a[i][j]==1)
      {
        return false;
      }
    }
  }
  for(int i=row+1;i<n;i++)
  {
    for(int j=row-2;j>=0;j--)
    {
      if(a[i][j]==1)
      {
        return false;
      }
    }
  }
  return true;
}
void solve(int n,int row,int column,int knights)
{
     if(knights==n)
     {
      cout<<"Next"<<endl;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
          cout<<a[i][j]<<" ";
        }
        cout<<endl;
       }
       countK++;
       return;
     }
     else if(row==n)
     {
       return;
     }
     /// Ya toh final configuration mein 1 hai ya 0
     if(canPlace(n,row,column))
     {
       a[row][column]=1;
       if(column==n-1)
        solve(n,row+1,0,knights+1);
       else
        solve(n,row,column+1,knights+1);
     }
     a[row][column]=0;  /// Backtrack final config mein 0 hai 
     if(column==n-1)
        solve(n,row+1,0,knights);
       else
        solve(n,row,column+1,knights);
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      a[i][j]=0;
    }
  }
   solve(n,0,0,0);
   cout<<countK;
}
