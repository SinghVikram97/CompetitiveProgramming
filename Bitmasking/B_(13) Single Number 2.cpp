https://leetcode.com/problems/single-number-ii/description/
https://drive.google.com/open?id=1fiBdQPJdQyqoF-CkBNPyWlqnmL1RnLBi
#include<bits/stdc++.h>
using namespace std;
int number(vector<int> v)
{
    int finalNumber=0;
    bool sareZero;
    /// Traverse the array 32 times as there are 32 bits
    for(int i=0;i<32;i++)
    {
        sareZero=true;
        int bitSum=0;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]!=0)
            {
                sareZero=false;
            }
            bitSum=bitSum+(v[j]&1);
            v[j]=v[j]>>1;
        }
        if(sareZero)
        {
            break;
        }
        finalNumber=((bitSum%3)<<i)|(finalNumber);
        /// Can't do finalNumber=(finalNumber<<1)|(bitSum%3)
    }
    return finalNumber;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<number(v);
}
