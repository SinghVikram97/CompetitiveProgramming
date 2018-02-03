https://drive.google.com/open?id=1XUTNA4UAdAFfmtNn2aWAghPPFwUqvoPd
https://drive.google.com/open?id=1TVqu8_bZcJUoemqyXWf4DdD-cfG9-9-8
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v(200009);
vector<ll> BIT(200009);
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
        set<ll> mySet;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            mySet.insert(v[i]);
        }
        map<ll,ll> myMap;
        ll index=1;
        for(auto it=mySet.begin();it!=mySet.end();it++)
        {
            myMap[*it]=index;
            index++;
        }
        for(int i=1;i<=n;i++)
        {
            v[i]=myMap[v[i]];
        }
        ll ans=0;
        for(int i=n;i>=1;i--)
        {
            update(1,v[i]);
            ans=ans+query(v[i]-1);
        }
        cout<<ans<<endl;
        for(int i=0;i<200009;i++)
        {
            BIT[i]=0;
        }
    }
}
