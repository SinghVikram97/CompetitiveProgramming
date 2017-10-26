Alice has mastered number theory, now he gives you the task of solving linear congruence. You need to print the minimum positive value of x which satisfy the following conditions:
x mod a0 = r0 
x mod a1 = r1 
.
.
x mod ak-1 = rk-1 
Every pair in a0.......ak-1 is co-prime.
Input Format:
First line contains single integer k. Second line contains numbers array 'a'. Third line contains remainder array 'r'.

Constraints:
The product of all numbers in array 'a' will fit in long long int.
Output Format:
Print integral value denoting minimum positive value of x satisfying the equations.

Sample Input:
3
3 4 5
2 3 1
Sample Output:
11

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
ll moduloInverse(ll a,ll b)  /// Modulo inverse of b wrt to a
{
   ll x,y;
   gcd(a,b,x,y);
   ll inverse;
   inverse=(y+a)%a;
   return inverse;
}
int main()
{
    ll k;
    cin>>k;
    vector<ll> num(k);
    vector<ll> rem(k);
    for(ll i=0;i<k;i++)
    {
        cin>>num[i];
    }
    for(ll i=0;i<k;i++)
    {
        cin>>rem[i];
    }
    ll product=1;
    for(ll i=0;i<k;i++)
    {
        product=product*num[i];
    }
    vector<ll> pp(k);
    for(ll i=0;i<k;i++)
    {
        pp[i]=(product)/(num[i]);
    }
    vector<ll> inv(k);
    for(ll i=0;i<k;i++)
    {
        inv[i]=moduloInverse(num[i],pp[i]);
    }
    ll ans=0;
    for(ll i=0;i<k;i++)
    {
        ans=(ans+((rem[i]%product)*(pp[i]%product)*(inv[i]%product))%product)%product;
    }
    cout<<ans;
}

