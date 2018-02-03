https://drive.google.com/open?id=1vPTvsBqhe8TbIpRa1x-1e2TO393-eOMX
https://drive.google.com/open?id=1nxbbGH1_yyRVMnL-gEIOYhtdkOdoLzVm
https://drive.google.com/open?id=1BkAgCvq0MVfbEXmVv7a0D-OXTmuDFXxs
https://drive.google.com/open?id=1WMtCpjEwh1b2wCUENjE8XscwBmkZJ-3M
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
vector<long long int> v(200009);
vector<ll> BIT(10000009);
void update(ll inc,ll index)
{
    ll n=v.size()-1;
    ll i=index;
    /// Increment every i moving from index to i+(i&(-i))
    while(i<=n)
    {
        BIT[i]=BIT[i]+inc;
        i=i+(i&(-i));
    }
    return;
}
ll query(ll index)
{
    ll i=index;
    /// Query sum from 1 to i
    /// Decrement i moving from index to i-(i&(-i))
    ll ans=0;
    while(i>0)
    {
        ans=ans+BIT[i];
        i=i-(i&(-i));
    }
    return ans;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            cin>>v[i];
        }
        ll ans=0;
        for(ll i=n; i>=1; i--)
        {
            update(1,v[i]);
            ans=ans+query(v[i]-1);
        }
        cout<<ans<<endl;
        for(int i=0;i<10000009;i++)
        {
            BIT[i]=0;
        }
    }

}
