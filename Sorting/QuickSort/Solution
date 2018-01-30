#include<bits/stdc++.h>
using namespace std;
int partitionArray(vector<int> &v,int s,int e)
{
    /// Select pivot as last element
    int pivot=v[e];
    int wall=s-1;
    for(int i=s;i<e;i++)
    {
        if(v[i]<pivot)
        {
            wall++;
            swap(v[wall],v[i]);
        }
    }
    wall++;
    swap(v[wall],v[e]);
    return wall;
}
void quick_sort(vector<int> &v,int s,int e)
{
    if(s>e)
    {
        /// Out of bound
        return;
    }
    else if(s==e)
    {
        /// Single element already sorted
        return;
    }
    int pivotPosition=partitionArray(v,s,e);
    /// Sort arrays from s to pivotPosition-1 and pivotPosition+1 to e
    quick_sort(v,s,pivotPosition-1);
    quick_sort(v,pivotPosition+1,e);
    return;
}
int main()
{
    cout<<"Enter no of elements in array"<<endl;
    int n;
    cin>>n;
    cout<<"Enter elements of array"<<endl;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    quick_sort(v,0,n-1);
    cout<<"Array after sorting is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }

}
