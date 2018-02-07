https://drive.google.com/open?id=1hDGzTYdukV2DHdmztOY6raewFm-RRiAB

#include<bits/stdc++.h>
using namespace std;
int changeBits(int &a,int &b)
{
    /// Count no of set bits in a^b
    /// As XOR 1 only if bits are different

    int xorAns=(a^b);
    int ans=0;

    while(xorAns>0)
    {
        /// See last bit by anding it with 1
        if(xorAns&1)
        {
            /// It means it is 1
            ans++;
        }
        xorAns=xorAns>>1;  /// Shift by 1 bit or discard last bit as we have already seen it
    }
    return ans;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<changeBits(a,b);
}
