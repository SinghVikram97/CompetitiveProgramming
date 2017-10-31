#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll squareRoot(ll n)
{
    /// smallest no b/w 1 to n whose square more than n
    ll start=1,end=n,mid;
    ll ans;
    while(start<=end)
    {
        mid=(start)+(end-start)/2;
        ll square=mid*mid;
        if(square>=n) /// equal because for perfect square
        {
            ans=mid;
            /// See if we have further less the ans
            /// By moving left
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    cout<<squareRoot(n);
}
