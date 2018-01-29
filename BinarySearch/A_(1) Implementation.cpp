https://drive.google.com/open?id=1nCc9lA3cCwVdYhvsfgf_8Qvf-jrraqHx
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &v,int element)
{
    int s,mid,e;
    s=0;
    e=v.size()-1;
    while(s<=e)      /// start=end when single element
    {
        mid=(s+e)/2;
        if(v[mid]==element)
            return mid;
        else if(element<v[mid])
            e=mid-1;
        else
            s=mid+1;
    }
    return -1;
}
int main()
{
    cout<<"Enter the no of elements in the array"<<endl;
    int n;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements of the array in sorted order"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"Enter element to search for"<<endl;
    int element;
    cin>>element;
    int pos=binarySearch(v,element);
    if(pos!=-1)
    {
        cout<<"Element found at index "<<pos;
    }
    else
    {
        cout<<"Element not found in array";
    }
}
