/// TRY FOR 1000000000000000000
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll square_root(ll n)
{
    if(n==0)
        return n;
    ll s,e,mid;
    s=1,e=n;
    ll ans;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(mid==n/mid)         /// By default division is floor
            return mid;
        else if(mid<n/mid)     /// By default division is floor
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    cout<<square_root(n);
}
