https://drive.google.com/open?id=1OhGDN8JIkClnowhBd32X6ct4Hvh12W_5
https://drive.google.com/open?id=1TXXcYjTmeXJ14KHbpuIabcbz2HOBWqFX
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
    int a,b,c;
    cin>>a>>b>>c;
    pair<int,int> ans=gcd(a,b);
    int g=(a*ans.first)+(b*ans.second);
    cout<<g<<endl;
    cout<<(ans.first*c)/g<<" "<<(ans.second*c)/g<<endl;
}
