https://drive.google.com/open?id=1EeuLmTA_1SpoJoSKovXN_d7ym4Dp360s
#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &v,int element)
{
   int s,mid,e;
   s=0;
   e=v.size()-1;
   int lower;
   while(s<=e)
   {
       mid=(s+e)/2;
       if(v[mid]==element)
       {
           lower=mid;
           /// See if we can find element to left of this
           e=mid-1;
       }
       else if(element<v[mid])
       {
           e=mid-1;
       }
       else
       {
           s=mid+1;
       }
   }
   return lower;
}
int upperBound(vector<int> &v,int element)
{
    int s,mid,e;
    s=0;
    e=v.size()-1;
    int upper;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(v[mid]==element)
        {
            upper=mid;
            /// See if we can move further right
            s=mid+1;
        }
        else if(element<v[mid])
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return upper;
}
int main()
{
    cout<<"Enter no elements in the array"<<endl;
    int n;
    cin>>n;
    cout<<"Enter elements of the array"<<endl;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"Enter element"<<endl;
    int element;
    cin>>element;
    cout<<"Lower bound of element is "<<lowerBound(v,element)<<endl;
    cout<<"Upper bound of element is "<<upperBound(v,element)<<endl;
    cout<<"Total occurrence of element in array "<<1+upperBound(v,element)-lowerBound(v,element)<<endl;
}
