https://drive.google.com/open?id=17i67uV5gUpELfQ60ukOY8cjA6ayOxqko
https://drive.google.com/open?id=1VnjYfG6hRsLnQ2pQUyH9FxfcdTk8SDFF
#include<bits/stdc++.h>
using namespace std;
pair<int,int> gcd(int a,int b)
{
    if(b==0)
    {
        return make_pair(1,0);
    }
    int currentX,currentY;
    pair<int,int> nextXY;
    nextXY=gcd(b,a%b);
    currentX=nextXY.second;
    currentY=nextXY.first-(floor(a/b)*nextXY.second);
    return make_pair(currentX,currentY);
}
int main()
{
    int a,m;
    cin>>a>>m;
    pair<int,int> ans=gcd(a,m);
    /// Check for 6 and 7 with simple ans.first
    cout<<(ans.first+m)%m<<endl;
}
