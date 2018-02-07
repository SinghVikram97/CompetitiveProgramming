https://drive.google.com/open?id=1gVK4qT8ycaXyG9cgNCCRBwjRPsrPGkSV
https://drive.google.com/open?id=1kDa_TI7ySDRc2XgTVclmO-kd2OW7EaMp

#include<bits/stdc++.h>
using namespace std;
void subsets(string s)
{
    int n=s.length();
    int powerSetSize=1<<n;
    for(int i=0;i<powerSetSize;i++)
    {
        /// See the bits of i
        int temp=i;
        /// Empty string
        string ans="";
        /// Traverse over n bits of i
        for(int j=0;j<n;j++)
        {
            if(temp&1)
            {
                /// Bit is set take s[j] in subset
                ans.push_back(s[j]);
            }
            temp=temp>>1;
        }
        cout<<ans<<endl;
        ans.clear();
    }
}
int main()
{
    string s;
    cin>>s;
    subsets(s);
}
