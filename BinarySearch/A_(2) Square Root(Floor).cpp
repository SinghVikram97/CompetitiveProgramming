https://leetcode.com/problems/sqrtx/description/
https://drive.google.com/open?id=1ZVtxeQ03qNgDnuTT4Z2Q4MtHbFDZBQCG
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
        if(mid*mid==n)
            return mid;
        else if(mid*mid<n)
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
