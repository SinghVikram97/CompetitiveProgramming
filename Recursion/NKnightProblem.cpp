#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int countK=0;
bool canPlace(int n,int row,int column)
{
  for(int i=row-2,j=column+1;i>=0,j<n;i=i-2,j=j+1)
  {

      if(a[i][j]==1)
      {
         // cout<<"Hi1";
        return false;
      }

  }
  for(int i=row-2,j=column-1;i>=0,j>=0;i=i-2,j=j-1)
  {

      if(a[i][j]==1)
      {
         // cout<<"Hi2";
        return false;
      }

  }
//  for(int i=row+2,j=column+1;i<n,j<n;i=i+2,j=j+1)
//  {
//
//      if(a[i][j]==1)
//      {
//          //cout<<"hi3";
//        return false;
//      }
//  }
//  for(int i=row+2,j=column-1;i<n,j>=0;i=i+2,j=j-1)
//  {
//
//      if(a[i][j]==1)
//      {
//          //cout<<"hi4";
//        return false;
//      }
//
//  }
  for(int i=row-1,j=column-2;i>=0,j>=0;i=i-1,j=j-2)
  {

      if(a[i][j]==1)
      {
          //cout<<"hi5";
        return false;
      }

  }
  for(int i=row-1,j=column+2;i>=0,j<n;i=i-1,j=j+2)
  {

      if(a[i][j]==1)
      {
         // cout<<"hi6";
        return false;
      }

  }
//  for(int i=row+1,j=column-2;i<n,j>=0;i=i+1,j=j-2)
//  {
//
//      if(a[i][j]==1)
//      {
//          //cout<<"hi7";
//        return false;
//      }
//
//  }
//  for(int i=row+1,j=column+2;i<n,j<n;i=i+1,j=j+2)
//  {
//
//      if(a[i][j]==1)
//      {
//         // cout<<"hi8";
//        return false;
//      }
//
//  }
  return true;
}
void solve(int n,int row,int column,int knights)
{
     if(knights==n)
     {
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
     a[row][column]=0;
     if(column==n-1)
        solve(n,row+1,0,knights);
       else
        solve(n,row,column+1,knights);
}
void solve1(int n,int row,int column,int knights)
{
     if(knights==n)
     {
      for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
          if(a[i][j]==1)
          {
            cout<<"{"<<i<<"-"<<j<<"}"<<" ";
          }
        }
       }
       cout<<" ";
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
        solve1(n,row+1,0,knights+1);
       else
        solve1(n,row,column+1,knights+1);
      a[row][column]=0;
     }
     if(column==n-1)
        solve1(n,row+1,0,knights);
       else
        solve1(n,row,column+1,knights);
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
   cout<<countK<<endl;
   solve1(n,0,0,0);
}
