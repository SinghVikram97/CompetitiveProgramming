GCD(a,b)=x*a+y*b
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll ans=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-floor((double)a/b)*y1;
    return ans;
}
int main()
{
  ll a,b;
  cin>>a>>b;
  ll x,y;
  cout<<gcd(a,b,x,y)<<endl;
  cout<<x<<" "<<y<<endl;
  cout<<(x*a)+(b*y)<<endl;
}
