https://drive.google.com/open?id=1MKHV2x5eqD8oZqzwMQ5Wo46xobALI0OP
#include<bits/stdc++.h>
using namespace std;
void update(vector<int> &BIT,vector<int> &v,int index,int value)
{
    /// Since 1 based indexing
    int n=v.size()-1;
    /// Update all nodes which have this index in range
    /// Move i=index to i+(i&(-i))
    int i=index;
    while(i<=n)
    {
       BIT[i]=max(BIT[i],value);
       i=i+(i&(-i));
    }
    return;
}
int query(vector<int> &BIT,vector<int> &v,int index)
{
    int i=index;
    /// Move i from index to i-(i&(-i))
    int ans=-1;
    while(i>0)
    {
        ans=max(ans,BIT[i]);
        i=i-(i&(-i));
    }
    return ans;
}
int main()
{
    cout<<"Enter the number of elements in array"<<endl;
    int n;
    cin>>n;
    /// 1 based indexing for both
    vector<int> v(n+1);
    vector<int> BIT(n+1);
    cout<<"Enter elements of the array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        update(BIT,v,i,v[i]);
    }
    cout<<"Enter the number of queries"<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        cout<<"Enter the range"<<endl;
        int index;
        cin>>index;
        cout<<query(BIT,v,index)<<endl;
    }
}
