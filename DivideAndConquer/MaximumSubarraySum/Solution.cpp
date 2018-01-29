#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll prefixSuffixSum(vector<ll> &v,ll s,ll mid,ll e)
{
    /// Left wala from s to mid ka suffix dekhna hai
    ll maxSuffix=0;
    ll current_sum=0;
    for(ll i=mid;i>=s;i--)
    {
       current_sum=current_sum+v[i];
       if(current_sum>=maxSuffix)
       {
           maxSuffix=current_sum;
       }
    }
    /// Right wala from mid+1 to e ka prefix dekhna hai
    ll maxPrefix=0;
    current_sum=0;
    for(ll i=mid+1;i<=e;i++)
    {
        current_sum=current_sum+v[i];
        if(current_sum>=maxPrefix)
        {
            maxPrefix=current_sum;
        }
    }
    return maxPrefix+maxSuffix;
}
ll maximum_sum(vector<ll> &v,ll s,ll e)
{
    /// Out of bounds
    if(s>e)
    {
        return INT_MAX; /// Not possible
    }
    /// Single element
    if(s==e)
    {
        /// Sum is equal to element itself
        return v[s];
    }
    /// 3. Options
    ll mid=(s+e)/2;
    /// 1. Left wale sub array se
    ll op1=maximum_sum(v,s,mid);
    ll op2=maximum_sum(v,mid+1,e);
    ll op3=prefixSuffixSum(v,s,mid,e);
    return max(op1,max(op2,op3));
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        cout<<maximum_sum(v,0,n-1)<<endl;
    }
}
