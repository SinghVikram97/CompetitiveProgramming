https://drive.google.com/open?id=1Cd4cr592gPWhUmQ0RFdlBrXU6z-3Lpvn
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    /// Store a as string
    string a;
    ll b;
    cin>>a>>b;
    /// Take Modulo a%b
    ll A=0;
    for(int i=0;i<a.length();i++)
    {
        A=(((A*10)%b)+((a[i]-'0')%b))%b;
    }
    /// This reduces A to a number between 0 to b-1
    cout<<gcd(b,A);
}
