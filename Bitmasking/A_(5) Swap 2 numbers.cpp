https://drive.google.com/open?id=1k42_Q4NinaRyeP-lc_rgPgNca3UltyYM

#include<bits/stdc++.h>
using namespace std;
void swapNo(int &a,int &b)
{
    int xorAns=a^b;
    a=xorAns^a;
    b=xorAns^b;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"Numbers before swapping "<<a<<" "<<b<<endl;
    swapNo(a,b);
    cout<<"Numbers after swapping "<<a<<" "<<b<<endl;
}
