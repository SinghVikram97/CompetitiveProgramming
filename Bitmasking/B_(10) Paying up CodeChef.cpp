#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,amount;
        cin>>n>>amount;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        bool hua=false;
        int powerSetSize=1<<n;
        /// Generate all numbers between 0 to 2^n-1
        for(int i=0;i<powerSetSize;i++)
        {
            int temp=i;
            int ans=0;
            /// See if bit is set or not from 0 to n-1th bit
            for(int j=0;j<n;j++)
            {
                if(temp&1)
                {
                    /// Take jth number
                    ans=ans+v[j];
                }
                temp=temp>>1;
            }
            if(ans==amount)
            {
                hua=true;
                break;
            }
        }
        if(hua)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}
