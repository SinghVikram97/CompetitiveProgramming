#include<bits/stdc++.h>
using namespace std;
void buildTree(vector<int> &segTree,vector<int> &v,int index,int s,int e)
{
    /// Out of bounds
    if(s>e)
    {
        return;
    }
    /// Leaf Node
    if(s==e)
    {
        segTree[index]=v[s];
        return;
    }
    int mid=(s+e)/2;
    /// Else build the left tree
    buildTree(segTree,v,2*index,s,mid);
    buildTree(segTree,v,2*index+1,mid+1,e);
    /// Store the minimum of the 2 at this index
    segTree[index]=min(segTree[2*index],segTree[2*index+1]);
}
long long int query(vector<int> &segTree,vector<int> &v,int index,int s,int e,int qs,int qe)
{
    /// 1.No overlap
    if(qs>e || qe<s)
    {
        return INT_MAX;
    }
    /// 2.Complete overlap
    if(qs<=s && qe>=e)
    {
        return segTree[index];
    }
    /// 3.Partial overlap
    int mid=(s+e)/2;
    /// Call left and right and return their minimum
    long long int leftAns=query(segTree,v,2*index,s,mid,qs,qe);
    long long int rightAns=query(segTree,v,2*index+1,mid+1,e,qs,qe);
    return min(leftAns,rightAns);
}
void update(vector<int> &segTree,vector<int> &v,int index,int s,int e,int qs,int qe,int inc)
{
    /// 1.No overlap
    if(qs>e || qe<s)
    {
        return;
    }
    /// 2. Leaf Node
    if(s==e)
    {
        /// No case of complete overlap see in photos
        segTree[index]+=inc;
        return;
    }
    int mid=(s+e)/2;
    /// 3. Partial overlap call both sides
    update(segTree,v,2*index,s,mid,qs,qe,inc);
    update(segTree,v,2*index+1,mid+1,e,qs,qe,inc);
    /// 4. Now update this index( Very imp. step har bar chut jata hai)
    segTree[index]=min(segTree[2*index],segTree[2*index+1]);
    return;
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    vector<int> segTree(4*n+1);
    buildTree(segTree,v,1,1,n);
    for(int i=0;i<q;i++)
    {
        char choice;
        cin>>choice;
        if(choice=='q')
        {
            int qs,qe;
            cin>>qs>>qe;
            cout<<query(segTree,v,1,1,n,qs,qe)<<endl;
        }
        else
        {
            int qs,qe,inc;
            cin>>qs>>qe>>inc;
            update(segTree,v,1,1,n,qs,qe,inc);
        }
    }
}
