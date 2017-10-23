https://hack.codingblocks.com/contests/c/126/268
Let's define a new game of snakes and ladders. There is only one dimension of n cells. Each cell either contains a snake or ladder. One can simply take a jump of not more than k cells. A person cannot step on a snake. However, s/he can jump over a snake.
Alice is excited to play this game and is asking you to calculate the number of ways to finish the game.
Game starts at 1st cell and ends at the nth cell. It is guaranteed that there is a ladder at the 1st cell.
Since the number can be large, output the answer modulo (109+7).

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    vector<ll> ans(n+1); /// index i denotes number of steps to reach ith step
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(v[i]==1)
        {
            ans[i]=0;
        }
        else
        {
            for(int j=1;j<=k;j++)
           {
            if(i-j>0)
            {
                ans[i]=((ans[i]%m)+(ans[i-j]%m))%m;
            }
           }
        }
    }
    cout<<ans[n]%m<<endl;
 }

