https://hack.codingblocks.com/practice/p/66/463
https://drive.google.com/open?id=1W6eQIcNBtmD7H6r_CAu9zQDBaLx_yp2d
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isSet(ll n,ll i)
{
    /// Find out whether ith bit is set or not
    /// Generate a mask with all zero except ith bit
    ll mask=1<<i;
    /// And with 1
    if(mask&n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void singleNoII(vector<ll> v)
{
    ll xorAns=0;
    /// Traverse the array to calculate xor
    for(ll i=0;i<v.size();i++)
    {
        xorAns=xorAns^v[i];
    }

    /// Select a set bit in final xor
    ll setBitpos=0;
    while(xorAns!=0)
    {
        if(isSet(xorAns,setBitpos))
        {
            break;
        }
        xorAns=xorAns>>1;
        setBitpos++;
    }
    vector<ll> bitIsSet;
    vector<ll> bitOffSet;
    /// Divide numbers llo 2 groups
    for(ll i=0;i<v.size();i++)
    {
        if(isSet(v[i],setBitpos))
        {
            bitIsSet.push_back(v[i]);
        }
        else
        {
            bitOffSet.push_back(v[i]);
        }
    }
    ll number1=0,number2=0;
    for(ll i=0;i<bitIsSet.size();i++)
    {
        number1=number1^bitIsSet[i];
    }
    for(ll i=0;i<bitOffSet.size();i++)
    {
        number2=number2^bitOffSet[i];
    }
    cout<<"Two numbers are "<<number1<<" "<<number2<<endl;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    singleNoII(v);
}
