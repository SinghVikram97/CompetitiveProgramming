https://leetcode.com/problems/search-in-rotated-sorted-array/
https://drive.google.com/open?id=1yk-2ejgBAlC9GfMbeU5LNJ5cANk1bNSh
https://drive.google.com/open?id=121yhiIV--wqi_7oTIy0XjYRoiSPN3vU5
#include<bits/stdc++.h>
using namespace std;
int searchSortedRotated(vector<int> v,int element)
{
    int s,mid,e;
    s=0;
    e=v.size()-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        /// If v[mid] is the element itself return
        if(v[mid]==element)
            return mid;

        /// If left unsorted means right is sorted
        else if(v[s]>=v[mid])
        {
            /// We can find if element lies in right or not as it is sorted
            if(mid+1<=e && element>=v[mid+1] && element<=v[e])
            {
                /// Search in right part
                s=mid+1;
            }
            else
            {
                /// Search in left part
                e=mid-1;
            }
        }
        /// If right unsorted means left is sorted
        else if(v[e]<=v[mid])
        {
            /// We can find if element lies in left or not as it is sorted
            if(mid-1>=s && element<=v[mid-1] && element>=v[s])
            {
                /// Search in left part
                e=mid-1;
            }
            else
            {
                /// Search in right part
                s=mid+1;
            }
        }
        /// It means both are sorted
        else
        {
            if(element<v[mid] && element>=v[s])
            {
                /// Search in left part
                e=mid-1;
            }
            else
            {
                /// Search in right part
                s=mid+1;
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
    cout<<"Enter element to search for"<<endl;
    int element;
    cin>>element;
    int positon=searchSortedRotated(v,element);
    if(positon==-1)
    {
        cout<<"Element does not exist in array"<<endl;
    }
    else
    {
        cout<<"Element found at position "<<positon<<endl;
    }
}
