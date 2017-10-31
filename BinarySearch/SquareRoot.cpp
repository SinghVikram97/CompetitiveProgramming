#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll squareRoot(ll n)
{
    /// largest no b/w 1 to n whose square less than n
    ll start=1,end=n,mid;
    ll ans;
    while(start<=end) 
    {
        mid=(start+end)/2;
        if(mid*mid<=n)  /// equal because for perfect square
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
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
