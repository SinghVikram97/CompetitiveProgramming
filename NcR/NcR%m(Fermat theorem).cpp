#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll m=1000000007;
ll power(ll x,ll y)
{
    if(y==0)
        return 1;
    ll smallPower=(power(x,y/2))%m;
    smallPower=((smallPower%m)*(smallPower%m))%m;
    if(y%2==0)
        return smallPower;
    else
        return ((smallPower%m)*(x%m))%m;
}
ll modularInverse(ll r,ll m)
{
    return power(r,m-2);
}
ll nChooseR(ll n,ll r)
{
    if(r==0)
        return 1;
    ll fact[n+1];
    fact[0]=1;
    for(ll i=1;i<=n;i++)
    {
        fact[i] = (fact[i-1]*i)%m;
    }
    return (((fact[n]%m)* ((modularInverse(fact[r], m)) % m))%m *((modularInverse(fact[n-r], m) % m)) )% m;
}
int main()
{
    ll n,r;
    cin>>n>>r;
    cout<<nChooseR(n,r);
}
