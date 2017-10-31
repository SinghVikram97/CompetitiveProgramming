#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mergeArrays(ll a[],ll left[],ll right[],int leftSize,int rightSize)
{
    int count=0;
    int i=0,j=0,k=0;
    while(j!=leftSize && k!=rightSize)
    {
        if(left[j]<=right[k])
        {
            a[i]=left[j];
            i++;
            j++;
        }
        else
        {
            a[i]=right[k];
            count=count+(leftSize-j);
            i++;
            k++;
        }
    }
    while(j!=leftSize)
    {
        a[i]=left[j];
        i++;
        j++;
    }
    while(k!=rightSize)
    {
        a[i]=right[k];
        i++;
        k++;
    }
    return count;
}
int mergeSort(ll a[],int n) /// Here n is no of elements
{
    if(n==1)
    {
        return 0;
    }
    /// Divide array to 2 parts
    /// Every array is 0 to n-1 {n elements}
    int mid=(n-1)/2; /// left from (0 to mid) and right from (mid+1,n-1)
    ll left[mid+1];
    ll right[n-(mid+1)];
    for(ll i=0;i<mid+1;i++)
    {
        left[i]=a[i];
    }
    for(ll i=0;i<(n-mid-1);i++)
    {
        right[i]=a[mid+i+1];
    }
    /// Sort these 2 arrays
    int leftKa=mergeSort(left,mid+1);
    int rightKa=mergeSort(right,n-mid-1);
    /// Merge these 2 sorted arrays
    int mergeKa=mergeArrays(a,left,right,mid+1,n-mid-1);
    return leftKa+rightKa+mergeKa;
}
int main()
{
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<mergeSort(a,n);
}
