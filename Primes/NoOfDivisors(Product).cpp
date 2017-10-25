#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
ll p[1000005]={0};
void primeFactors(ll n,unordered_map<ll,ll> &myMap)
{
   while(n!=1)
   {
       /// n pe dekho kya pda hai
       myMap[p[n]]++;
       /// next dekho n/jo mila
       n=n/p[n];
   }
}
void preCompute()
{
    for(ll i=2;i<1000005;i++)
    {
        if(p[i]==0) /// 0 means unmarked
        {
            p[i]=i;
            for(ll j=i*i;j<1000005;j=j+i)
            {
                if(p[j]==0)  /// Not marked ex 12
                {
                    p[j]=i;
                }
            }
        }
    }
}
int main()
{
    preCompute();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
        }
        unordered_map<ll,ll> myMap;
        for(ll i=0;i<n;i++)
        {
            primeFactors(v[i],myMap);
        }
        ll ans=1;
        for(auto it=myMap.begin();it!=myMap.end();it++)
        {
            ans=((ans%m)*(((*it).second)%m+1)%m)%m;
        }
        cout<<ans<<endl;
    }
}
