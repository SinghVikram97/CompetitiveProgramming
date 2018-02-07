https://drive.google.com/open?id=1u8A3JggRjanSULua1P9mpdVCjSB8EtQr
https://drive.google.com/open?id=1ZX1TIrQ0p3szGolM_JJYrHCawV65cDGe
https://drive.google.com/open?id=1igV6jAp0NDe78z9IlE-6U3OsayWgcUDS

#include<bits/stdc++.h>
using namespace std;
int countBits1(int a)
{
    int ans=0;
    while(a!=0)
    {
        if(a&1)
        {
            ans++;
        }
        a=a>>1;
    }
    return ans;
}
int countBits2(int a)
{
    /// Removes last set bit in each iteration
    int ans=0;
    while(a)
    {
        ans++;
        a=a&(a-1);
    }
    return ans;
}
int main()
{
    int a;
    cin>>a;
    cout<<countBits1(a)<<endl;
    cout<<countBits2(a)<<endl;
}
