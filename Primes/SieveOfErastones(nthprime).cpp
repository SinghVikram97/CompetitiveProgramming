Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.


Input Format:
Single line containing integral value n.

Constraints:
1<=n<=5000000
Output Format:
Integral value denoting nth prime number.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int p[86028122];
void sieve()
{
    for(ll i=2;i<86028122;i++)
    {
       if(i%2==0)
       {
           p[i]=0;
       }
       else
       {
           p[i]=1;
       }
    }
    p[2]=1;
    p[0]=0;
    p[1]=0;
    for(ll i=3;i<86028122;i=i+2)
    {
        if(p[i]) ///Unmarked
        {
            for(ll j=i*i;j<86028122;j=j+i)
            {
                p[j]=0;
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    sieve();
    ll count=0;
    ll i=0;
    ll n;
    cin>>n;
    while(count!=n)
    {
        if(p[i]==1)
        {
            count++;
        }
        i++;
    }
    cout<<i-1;
}
