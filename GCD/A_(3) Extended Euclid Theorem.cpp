https://drive.google.com/open?id=1dgxDQ3lH6XzuhfNrYrGlFYQSxOS51GYk
https://drive.google.com/open?id=1SXn4eIvEymlJoA7gBmGR8nxfHQkRDmAR
#include<bits/stdc++.h>
using namespace std;
pair<int,int> gcd(int a,int b)
{
    if(b==0)
    {
        return make_pair(1,0);
    }
    int currentX,currentY;
    pair<int,int> nextXY=gcd(b,a%b);
    currentX=nextXY.second;
    currentY=nextXY.first-(floor(a/b)*nextXY.second);
    return make_pair(currentX,currentY);
}
int main()
{
    int a,b;
    cin>>a>>b;
    pair<int,int> ans=gcd(a,b);
    cout<<ans.first<<" "<<ans.second<<endl;
}
