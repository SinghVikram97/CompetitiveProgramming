/// https://en.wikipedia.org/wiki/Eight_queens_puzzle
#include<bits/stdc++.h>
using namespace std;
bool canPlace(vector<vector<int> > a,int n,int row,int col)
{
    /// Col wise
    for(int i=0;i<n;i++)
    {
        if(a[i][col]==1 && i!=row)
        {
            return false;
        }
    }
    /// Principal diagonal wise upward
    int i=row,j=col;
    while(i>=0 && j>=0)
    {
        if(a[i][j]==1 && i!=row && j!=col)
        {
            return false;
        }
        i--;
        j--;
    }
    /// Dusra diagonal upward
    i=row;
    j=col;
    while(i>=0 && j<n)
    {
        if(a[i][j]==1 && i!=row && j!=col)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
void karSakteHain(int n,vector<vector<int> > &a,int row,int &count)
{
    if(row==n) /// Agar last tak pahunch gye to increase count
    {
        count++;
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(canPlace(a,n,row,j))
        {
            /// Kardo place
            a[row][j]=1;
            karSakteHain(n,a,row+1,count);
        }
        a[row][j]=0; /// Backtrack and check for other possible positions
    }
    /// Agar khi nhi kar paaye toh return last tak nhi pahunchne do
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > a(n,vector<int> (n));
    int count=0;
    karSakteHain(n,a,0,count);
    cout<<count;
}
