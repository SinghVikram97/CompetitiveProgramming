/// TRY FOR 1000000000000000000
/// TRY FOR 10 wrong answer if we don't use ceil and double
https://drive.google.com/open?id=1aj8nWAMmaj_iI9Sgi0G568vjd6cqvI-m
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
        if(mid==ceil((double)n/mid))
            return mid;
        else if(mid>ceil((double)n/mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
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
