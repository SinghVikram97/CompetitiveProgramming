/// Spoj favourite die
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=ans+((double)n/i);
        }
        cout<<fixed;
        cout<<setprecision(2);
        cout<<ans<<endl;
    }
}
