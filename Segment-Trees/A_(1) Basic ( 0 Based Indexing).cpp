#include<bits/stdc++.h>
using namespace std;
void buildTree(vector<int> &segTree,vector<int> &v,int index,int s,int e)
{
    /// s and e not valid
    if(s>e)
    {
        return;
    }
    /// Leaf node fill the array element
    if(s==e)
    {
        segTree[index]=v[s];
        return;
    }
    int mid=(s+e)/2;
    /// Build left tree
    buildTree(segTree,v,2*index,s,mid);
    /// Build right tree
    buildTree(segTree,v,2*index+1,mid+1,e);
    /// Fill minimum of these 2 at current index
    segTree[index]=min(segTree[2*index],segTree[2*index+1]);
    return;
}
long long int query(vector<int> &segTree,vector<int> &v,int index,int qs,int qe,int s,int e)
{
    /// 1. No overlap condition
    if(qs>e || qe<s)
    {
        return INT_MAX;
    }
    /// 2. Complete overlap condition
    if(qs<=s && qe>=e)
    {
        return segTree[index];
    }
    /// 3. Partial overlap
    int mid=(s+e)/2;
    /// Call on both sides
    long long int leftAns=query(segTree,v,2*index,qs,qe,s,mid);
    long long int rightAns=query(segTree,v,2*index+1,qs,qe,mid+1,e);
    return min(leftAns,rightAns);
}
void updateTree(vector<int> &segTree,vector<int> &v,int index,int s,int e,int value,int givenIndex)
{
    /// No overlap
    if(index>e || index<e)
    {
        return;
    }
    /// Complete overlap so leaf node and update
    if(s==e && index==givenIndex)
    {
        segTree[index]=value;
        return;
    }
    /// Partial Overlap
    int mid=(s+e)/2;
    /// Call both sides
    updateTree(segTree,v,2*index,s,mid,value,givenIndex);
    updateTree(segTree,v,2*index+1,mid+1,e,value,givenIndex);
    return;
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);   /// Array is 0 based indexing
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> segTree(4*n+1);  /// Segment tree is 1 based indexing
    buildTree(segTree,v,1,0,n-1);
    for(int i=0;i<q;i++)
    {
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<query(segTree,v,1,l,r,0,n-1)<<endl;
        }
        else
        {
            int value,givenIndex;
            cin>>value>>givenIndex;
            updateTree(segTree,v,1,0,n-1,value,givenIndex);
        }
    }
}
