#include<bits/stdc++.h>
using namespace std;
void print(int n,string s,int opened) /// String passed by value
{
    if(s.length()==2*n)
    {
        if(opened==0)
        {
            cout<<s<<endl;
        }
        return;
    }
    else
    {
        /// Push '(' ya ')'
        if(opened!=0)   /// Opened denotes kitne open hai abhi
        {
            s.push_back(')');
            print(n,s,opened-1);
            s.pop_back();
            s.push_back('(');
            print(n,s,opened+1);
        }
        else  /// Open=0 hai toh close krne ki zaroot nhi
        {
            s.push_back('(');
            print(n,s,opened+1);
        }

    }

}
int main()
{
    int n;
    cin>>n;
    string s;
    print(n,s,0);
}
