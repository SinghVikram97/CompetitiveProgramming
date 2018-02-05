https://hack.codingblocks.com/contests/c/56/187
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/// a=(b*m)+(a%b)
/// So gcd should divide a and b
/// So it should divide (b*m) and (a%b)
/// So gcd(a,b)=gcd(b,a%b)

ll gcd(ll a,ll b)
{
    if(b==0)                 /// Gcd of a number with 0 is number itself
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
   ll a,b;
   cin>>a>>b;
   cout<<gcd(a,b);
}
