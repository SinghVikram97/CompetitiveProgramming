https://drive.google.com/open?id=1P3cJ3lPlLOl3_lENN_FIfulc6SImbwXw
https://drive.google.com/open?id=1YrvVPBfS-azcgrai-Vw9i0RhIQWaNCZb

#include<bits/stdc++.h>
using namespace std;
void setBit1(int a,int i)
{
    /// Right shift i times
    a=a>>i;
    /// And with 1
    if(a&1)
    {
        cout<<"Bit is set"<<endl;
    }
    else
    {
        cout<<"Bit is not set"<<endl;
    }
    return;
}
void setBit2(int a,int i)
{
    /// Left swift 1 i times
    int temp=1<<i;
    /// And with given number
    if(a&temp)
    {
        cout<<"Bit is set"<<endl;
    }
    else
    {
        cout<<"Bit is not set"<<endl;
    }
    return;
}
int main()
{
    int a,i;
    cin>>a>>i;
    setBit1(a,i);
    setBit2(a,i);
}
