#include<bits/stdc++.h>
using namespace std;
bool canPlace(vector<vector<int> > a,int n,int row,int col)
{
    /// Row wise                         /// Can remove this as ek column mein ek hi hogi queen
    for(int i=0;i<n;i++)
    {
        if(a[row][i]==1 && i!=col)
        {
            return false;
        }
    }
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
    /// Downward            /// Can remove this as niche abhi koi queen nhi place hui hogi
    i=row;
    j=col;
    while(i<n && j<n)
    {
        if(a[i][j]==1 && i!=row && j!=col)
        {
            return false;
        }
        i++;
        j++;
    }
    /// Dusra diagonal downward                /// Can remove this as niche koi queen nhi hogi
    i=row;
    j=col;
    while(i<n && j>=0)
    {
        if(a[i][j]==1 && i!=row && j!=col)
        {
            return false;
        }
        i++;
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
bool karSakteHain(int n,vector<vector<int> > &a,int row)
{
    if(row==n)
    {
        return true;
    }
    for(int j=0;j<n;j++)
    {
        if(canPlace(a,n,row,j))
        {
            /// Place kardo
            a[row][j]=1;
            /// Next sare place karke dekho
            if(karSakteHain(n,a,row+1))
            {
                return true;
            }
            else
            {
                /// Try different position
                a[row][j]=0; /// Backtrack
                continue;
            }
        }
    }
    return false; /// Khi bhi nhi kar sakte

}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > a(n,vector<int> (n));
    if(karSakteHain(n,a,0))
    {
        cout<<"Possible";
    }
    else
    {
        cout<<"Not possible";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
