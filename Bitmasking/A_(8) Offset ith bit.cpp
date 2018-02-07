https://drive.google.com/open?id=1QetEaX9hoEq6a9XFmqKKUTFLUaq3sisK
https://drive.google.com/open?id=1NUrkXyl8w6oWpM2bNVOE0KEZ4nfC2-jq

#include<bits/stdc++.h>
using namespace std;
void offsetBit(int &a,int i)
{
    /// All bits 0 except ith bit
    int temp=1<<i;
    /// All bits 1 except ith bit
    temp=~temp;
    /// Take and with temp
    a=a&temp;
}
int main()
{
    int a,i;
    cin>>a>>i;
    cout<<"Number before "<<a<<endl;
    offsetBit(a,i);
    cout<<"Number after "<<a<<endl;
}
