#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m=1000000007;
ll stringToInt(string num,ll mod)
{
    ll ans=0;
    for(int i=0;i<num.length();i++)
    {
        ans=(((ans*10)%mod)+((num[i]-'0')%mod))%mod;
    }
    return ans;
}
ll power(ll x,ll y)
{
    /// x^y
    if(y==0)
        return 1;

    ll smallPower=power(x,y/2);
    smallPower=((smallPower%m)*(smallPower%m))%m;

    if(y%2==0)
        return smallPower;
    else
        return smallPower*x;

}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      string a,b;
      cin>>a>>b;
      ll A=stringToInt(a,m);
      //cout<<A<<endl;
      ll B=stringToInt(b,m-1);
      //cout<<B<<endl;
      ll ans=power(A,B);
      cout<<ans%m<<endl;
  }
}
