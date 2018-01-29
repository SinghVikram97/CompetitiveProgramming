#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> segTree(1000005);
vector<ll> v(1000005);
vector<ll> lazy(1000005);
void buildTree(ll index,ll s,ll e)
{
    /// 1. Out of bounds
    if(s>e)
    {
        return;
    }
    /// 2. Leaf Node
    if(s==e)
    {
        segTree[index]=v[s];
        return;
    }
    /// Build both left and right subtrees
    ll mid=(s+e)/2;
    /// Build left subtree
    buildTree(2*index,s,mid);
    /// Build right subtree
    buildTree(2*index+1,mid+1,e);
    /// Fill element at current index
    segTree[index]=min(segTree[2*index],segTree[2*index+1]);
    return;
}
ll query(ll index,ll s,ll e,ll qs,ll qe)
{
    /// If we reach a node resolve it first
    segTree[index]+=lazy[index];
    /// Pass lazy value to it's children if current node not a leaf node
    if(s!=e)
    {
      lazy[2*index]+=lazy[index];
      lazy[2*index+1]+=lazy[index];
    }
    /// Make lazy value of this node to zero
    lazy[index]=0;


    /// 1. No overlap
    if(qs>e || qe<s)
    {
        return INT_MAX;
    }
    /// 2. Complete overlap
    if(qe>=e && qs<=s)
    {
        /// Already resolved so yha lazy value for this node pehle hi 0 hogyi
        return segTree[index];
    }
    /// 3. Partial overlap
    ll mid=(s+e)/2;
    ll leftAns=query(2*index,s,mid,qs,qe);
    ll rightAns=query(2*index+1,mid+1,e,qs,qe);
    return min(leftAns,rightAns);
}
void update(ll index,ll s,ll e,ll qs,ll qe,ll inc)
{
    /// If we reach a node 1st resolve it
    segTree[index]+=lazy[index];
    /// Pass lazy value to it's children if current node not leaf node
    if(s!=e)
    {
      lazy[2*index]+=lazy[index];
      lazy[2*index+1]+=lazy[index];
    }
    /// Make lazy value of current node to zero
    lazy[index]=0;


    /// 1. No overlap
    if(qs>e || qe<s)
    {
        return;
    }

    /// 2. Complete overlap
    if(qe>=e && qs<=s)
    {
        /// Add increment to current node and return the value
        segTree[index]+=inc;

        /// Add increment to lazy value of it's children if current node not a leaf
        /// Node
        if(s!=e)
        {
          lazy[2*index]+=inc;
          lazy[2*index+1]+=inc;
        }
       return;
    }


    /// 3. Partial overlap
    ll mid=(s+e)/2;
    update(2*index,s,mid,qs,qe,inc);
    update(2*index+1,mid+1,e,qs,qe,inc);
    /// Update value at current node
    segTree[index]=min(segTree[2*index],segTree[2*index+1]);
    return;
}
int main()
{
    ll n,q;
    cin>>n>>q;
    /// 1 based indexing
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    /// Build the tree
    buildTree(1,1,n);
    /// Process the queries
    for(ll i=0;i<q;i++)
    {
        char choice;
        cin>>choice;
        if(choice=='q')
        {
            /// Query
            ll qs,qe;
            cin>>qs>>qe;
            cout<<query(1,1,n,qs,qe)<<endl;
        }
        else
        {
            /// Update
            ll qs,qe,inc;
            cin>>qs>>qe>>inc;
            update(1,1,n,qs,qe,inc);
        }
    }
}
