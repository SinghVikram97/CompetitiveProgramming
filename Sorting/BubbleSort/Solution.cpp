#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void bubble_sort(vector<ll> &v)
{
    ll n=v.size();
    /// AT each iteration largest element will bubble to last
    /// So if we sort n-1 elements then array will automatically be sorted
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=0;j<n-i-1;j++)
        {
            /// We don't need to check last element in 1st iteration
            /// second last element in 2nd iteration
            if(v[j]>v[j+1])
            {
                /// Push to right
                swap(v[j],v[j+1]);
            }
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    bubble_sort(v);
    for(ll i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}
