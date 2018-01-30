https://drive.google.com/open?id=1hgQ65lcyYky_c5KmW2qpxgfQLs9Trua4
https://drive.google.com/open?id=1zEpZxxpowXy1iZH5TxRdZk6S2XImiZwz
#include<bits/stdc++.h>
using namespace std;
int pivot(vector<int> v)
{
    int s,mid,e;
    s=0;
    e=v.size()-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        /// Pivot is middle element
        if(mid-1>=s && mid+1<=e && v[mid]>v[mid-1] && v[mid]>v[mid+1])
        {
            return mid;
        }
        /// Pivot is middle-1 element
        else if(mid-1>=s && mid+1<=e && v[mid]<v[mid-1] && v[mid]<v[mid+1])
        {
            return mid-1;
        }
        /// Pivot will be unsorted portion
        else
        {
            if(v[e]<=v[mid])  /// Remember equality
            {
                /// Right part will be unsorted
                s=mid+1;
            }
            /// else if(v[s]>=v[mid])
            /// For left part unsorted as well as fully sorted array ex.1 2 3 4
            else
            {
                /// Left part is unsorted
                e=mid-1;
            }
        }
    }
    return -1;
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
    int pivotPosition=pivot(v);
    if(pivotPosition==-1)
    {
        cout<<"Pivot does not exist"<<endl;
    }
    else
    {
        cout<<"Pivot at position "<<pivotPosition<<" and element is "<<v[pivotPosition]<<endl;
    }
}
